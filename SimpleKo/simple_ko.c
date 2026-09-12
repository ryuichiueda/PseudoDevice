/* simple_ko.c
Modified from the code on
http://homepage3.nifty.com/rio_i/lab/driver24/00201chardev.html
As shown in the code, this code can be distributed under GNU GPL.
*/
#include <linux/module.h>

MODULE_AUTHOR("Ryuichi Ueda");
MODULE_DESCRIPTION("minimum kernel object");
MODULE_LICENSE("GPL");

static char* msg = "module [baibai.o]";

int init_module( void )
{
    printk( KERN_INFO "%s : loaded  into kernel\n", msg );
    return 0;
}

void cleanup_module( void )
{
    printk( KERN_INFO "%s : removed from kernel\n", msg );
}
