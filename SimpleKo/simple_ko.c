//SPDX-FileCopyrightText: 2026 Ryuichi Ueda ryuichiueda@gmail.com
//SPDX-License-Identifier: GPL-2.0-only
#include <linux/module.h>

MODULE_AUTHOR("Ryuichi Ueda");
MODULE_DESCRIPTION("minimum kernel object");
MODULE_LICENSE("GPL");

static char* msg = "module [baibai.o]";

int init_module(void)
{
    printk( KERN_INFO "%s : loaded into kernel\n", msg );
    return 0;
}

void cleanup_module(void)
{
    printk( KERN_INFO "%s : removed from kernel\n", msg );
}
