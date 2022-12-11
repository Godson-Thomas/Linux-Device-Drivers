#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

int g_value=20;

MODULE_AUTHOR("Godson Thomas");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Load_Unload");


static int __init hello_init(void){


    printk("Hello World!!, value of g_value is %d\n",g_value);
    return 0;

}

static void __exit hello_exit(void){


    printk("unloaded:hello_world.ko\n");
   

}



module_init(hello_init);
module_exit(hello_exit);
