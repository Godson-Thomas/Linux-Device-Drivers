#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Godson Thomas");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Parameter ");

static int irq;
module_param(irq,int,0660);

static int debug;
module_param(debug,int,0660);

static char *devname;
module_param(devname,charp,0660);


static int simple_init(void)
{
	printk(KERN_WARNING "hello... irq=%d name=%s debug=%d\n",irq,devname,debug);
	return 0;
}

static void simple_cleanup(void)
{
	printk(KERN_WARNING "bye... irq=%d name=%s debug=%d\n",irq,devname,debug);
}

module_init(simple_init);
module_exit(simple_cleanup);
