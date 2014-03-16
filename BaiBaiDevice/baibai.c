/* baibai.c
Modified from the code on
http://homepage3.nifty.com/rio_i/lab/driver24/00201chardev.html

As shown in the code, this code can be distributed under GNU GPL.
*/
#include <asm/uaccess.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/spinlock.h>

MODULE_AUTHOR("Ryuichi Ueda");
MODULE_DESCRIPTION("2bai2bai!!!");
MODULE_LICENSE("GPL");

static int devmajor = 0x0123;
static char* devname  = "baibai";
static char* msg = "module [baibai.o]";

#define MAXBUF 32
static unsigned char devbuf[MAXBUF];
static int buf_pos;
static int access_num;
static spinlock_t spn_lock;

static int num;

static int baibai_open(struct inode* inode, struct file* filp);
static ssize_t baibai_write(struct file* filp, const char* buf, size_t count, loff_t* pos );
static ssize_t baibai_read( struct file* filp, char* buf, size_t count, loff_t* pos );
static int baibai_release( struct inode* inode, struct file* filp );
int unregister_baibai( unsigned int major, const char* name );

static struct file_operations baibai_fops = 
{
	owner   : THIS_MODULE,
	read    : baibai_read,
	write   : baibai_write,
	open    : baibai_open,
	release : baibai_release,
};

static int baibai_open(struct inode* inode, struct file* filp){
	printk( KERN_INFO "%s : open()  called\n", msg );

	spin_lock( &spn_lock );

	if(access_num){
		spin_unlock( &spn_lock );
		return -EBUSY;
	}

	access_num++;
	spin_unlock( &spn_lock );

	return 0;
}

static ssize_t baibai_read( struct file* filp, char* buf, size_t count, loff_t* pos )
{
	int copy_len;
	int i;
	long a;

	printk( KERN_INFO "%s : read()  called\n", msg );

	if(count > buf_pos)
		copy_len = buf_pos;
	else
		copy_len = count;

	char nbuf[MAXBUF];
	a = 0;
	kstrtol(devbuf,0,&a);
	a *= 2;

	if(a < 1000000 && a > -1000000)
		sprintf(nbuf,"%d\n",a);
	else
		sprintf(nbuf,"%d\n",0);

	int len;
	len = strlen(nbuf);

	if(copy_to_user( buf, nbuf,len )) {
		printk( KERN_INFO "%s : copy_to_user failed\n", msg );
		return -EFAULT;
	}

	*pos += copy_len;

	for (i = copy_len;i < buf_pos;i++)
		devbuf[i - copy_len] = devbuf[i];

	buf_pos -= copy_len;
	printk( KERN_INFO "%s : buf_pos = %d\n", msg, buf_pos );

	return copy_len;
}

static ssize_t baibai_write(struct file* filp, const char* buf, size_t count, loff_t* pos )
{
	int copy_len;

	printk( KERN_INFO "%s : write() called\n", msg );

	if (buf_pos == MAXBUF){
		printk( KERN_INFO "%s : no space left\n", msg );
		return -ENOSPC;
	}

	if(count > ( MAXBUF - buf_pos ))
		copy_len = MAXBUF - buf_pos;
	else
		copy_len = count;

	if(copy_from_user( devbuf + buf_pos, buf, copy_len )){
		printk( KERN_INFO "%s : copy_from_user failed\n", msg );
		return -EFAULT;
	}

	*pos += copy_len;
	buf_pos += copy_len;

	printk( KERN_INFO "%s : buf_pos = %d\n", msg, buf_pos );
	return copy_len;
}

static int baibai_release( struct inode* inode, struct file* filp )
{
	printk( KERN_INFO "%s : close() called\n", msg );

	spin_lock( &spn_lock );
	access_num--;
	spin_unlock( &spn_lock );

	return 0;
}

int init_module( void )
{
	if(register_chrdev(devmajor, devname, &baibai_fops)){
		printk( KERN_INFO "%s : register_chrdev failed\n" );
		return -EBUSY;
	}

	spin_lock_init( &spn_lock );
	printk( KERN_INFO "%s : loaded  into kernel\n", msg );

	return 0;
}

void cleanup_module( void )
{
	unregister_chrdev( devmajor, devname );
	printk( KERN_INFO "%s : removed from kernel\n", msg );
}
