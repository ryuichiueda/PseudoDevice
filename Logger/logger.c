//SPDX-FileCopyrightText: 2026 Ryuichi Ueda <ryuichiueda@gmail.com>
//SPDX-License-Identifier: GPL-2.0-only
#include <linux/module.h>
#include <linux/cdev.h>

MODULE_AUTHOR("Ryuichi Ueda");
MODULE_DESCRIPTION("read the device file and write to the kernel log");
MODULE_LICENSE("GPL");

char* msg = "module [logger.o]";
static int major = 333;

static ssize_t logger_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
    char buffer[256] = {0};
    long len = strncpy_from_user(buffer, buf, sizeof(char)*256);
    if (0 < len && len < 256) {
	buffer[len] = '\0';
    	printk( KERN_INFO "receive: %s\n", buffer);
    }
    return len;
}

static struct file_operations fops = {
    owner: THIS_MODULE,
    write: logger_write,
};

int init_module(void) {
    if(register_chrdev(major, "logger", &fops)) {
    	printk( KERN_INFO "%s : register_chrdev failed\n", msg );
        return -EBUSY;
    }

    printk(KERN_INFO "%s is loaded. major:%d\n", msg, major);
    return 0;
}

void cleanup_module(void) {
    unregister_chrdev(major, "logger");
    printk( KERN_INFO "%s : removed from kernel\n", msg );
}
