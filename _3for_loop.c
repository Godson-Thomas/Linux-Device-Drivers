#include <linux/init.h>
#include <linux/module.h>

MODULE_AUTHOR("Godson Thomas");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A Simple for loop");

static int start_print(void){

uint k;
for(k=0;k<10;k++){

    printk(KERN_ALERT "%d ok",k);
}
return 0;
}

static void exit_prog(void){
    printk(KERN_ALERT "Unloaded from the Kernel\n");
}
module_init(start_print);
module_exit(exit_prog);
