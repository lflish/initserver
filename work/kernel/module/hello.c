/*
 * hello world !!!
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int hello_init(void)
{
	printk(KERN_ALERT "init hello module !!\n");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "exit hello module !!\n");
}

module_init(hello_init);
module_exit(hello_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("lflish");
MODULE_DESCRIPTION("hello world module");
