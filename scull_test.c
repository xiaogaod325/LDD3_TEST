#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
MODULE_LICENSE("Dual BSD/GPL");
#define SCULL_MAJOR 100
#define SCULL_MINOR 1


extern int  i;
 
dev_t dev_num=MKDEV(SCULL_MAJOR,SCULL_MINOR);
static int hello_init(void)
{
    printk(KERN_ALERT "hello,export symbol i : %d \n ",i);
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "bye,world");

}

module_init(hello_init);
module_exit(hello_exit);
