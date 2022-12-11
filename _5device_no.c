#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Godson Thomas");
MODULE_DESCRIPTION("Device Registration,Implementing system calls");



// This function is called, when the device file is opened

static int driver_open(struct inode *device_file, struct file *instance) {
	printk("device_no: open was called!\n");
	return 0;
}

/**
 *  This function is called, when the device file is closed
 */
static int driver_close(struct inode *device_file, struct file *instance) {
	printk("device_no: close was called!\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

#define MYMAJOR 60

/**
 *  This function is called, when the module is loaded into the kernel
 */
static int __init ModuleInit(void) {
	int retval;
	printk("Hello, Kernel!\n");
	/* register device no. */
	retval = register_chrdev(MYMAJOR, "gdsn_device", &fops);
	if(retval == 0) {
		printk("device_no: registered Device number Major: %d, Minor: %d\n", MYMAJOR, 0);
	}
	else if(retval > 0) {
		printk("device_no: registered Device number Major: %d, Minor: %d\n", retval>>20, retval&0xfffff);
	}
	else {
		printk("devicez-no:Could not register device number!\n");
		return -1;
	}
	return 0;
}

/**
 *  This function is called, when the module is removed from the kernel
 */
static void __exit ModuleExit(void) {
	unregister_chrdev(MYMAJOR, "gdsn_device");
	printk("Goodbye, Kernel\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
