//SPDX-FileCopyrightText: 2026 Ryuichi Ueda <ryuichiueda@gmail.com>
//SPDX-License-Identifier: GPL-2.0-only
#include <linux/module.h>

MODULE_AUTHOR("Ryuichi Ueda");
MODULE_DESCRIPTION("read the device file and write to the kernel log");
MODULE_LICENSE("GPL");

char* msg = "module [logger.o]";

static ssize_t logger_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
	char buffer[256];
	if(copy_from_user(&buffer, buf, sizeof(char)*256))
		return -EFAULT;

    	printk( KERN_INFO "receive: %s\n", buffer );
        return strlen(buf);
}

static struct file_operations fops = {
	owner: THIS_MODULE,
	write: logger_write,
};

int init_module(void) {
    printk( KERN_INFO "%s : loaded into kernel\n", msg );
    return 0;
}

void cleanup_module(void) {
    printk( KERN_INFO "%s : removed from kernel\n", msg );
}
