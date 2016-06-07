#include<linux/init.h>
#include<linux/fs.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
MODULE_LICENSE("Dual BSD/GPL");
#define SCULL_MAJOR 100
#define SCULL_MINOR 0
int i=0;

EXPORT_SYMBOL(i);
 
dev_t dev_num=MKDEV(SCULL_MAJOR,SCULL_MINOR);
static int hello_init(void)
{
    int result;
    printk(KERN_ALERT "hello,world");
    if(SCULL_MAJOR)
       	result=register_chrdev_region(dev_num,4,"scull");
    else 
        result=alloc_chrdev_region(&dev_num,SCULL_MINOR,4,"scull");
    
     
    
    return 0;
}


static void hello_exit(void)
{
    printk(KERN_ALERT "bye,world");

}

module_init(hello_init);
module_exit(hello_exit);
