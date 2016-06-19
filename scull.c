#include<linux/init.h>
#include<linux/fs.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
MODULE_LICENSE("Dual BSD/GPL");
#define SCULL_MAJOR 100
#define SCULL_MINOR 0
int i=0;

EXPORT_SYMBOL(i);
 
struct scull_dev{
	struct scull_qset *data;
	int quantum;
	int qset;
	unsigned long size;
	unsigned int accesskey;
	struct semaphore sem;
	struct cdev cdev;
}


loff_t scull_llseek(struct file * filep,loff_t off,int whence)
{

    return 0;
}  

int scull_open(struct inode * inode,struct file * filep)
{
    return 0;

}


ssize_t scull_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
 
 {
 return 0;
 }

int scull_write(struct file *filp,const char __user *buff,size_t count,loff_t *f_off)
{
    return 0;

}

long scull_ioctl(struct file *filp,unsigned int cmd,unsigned long arg)
 {
    return 0;
 
 }
 
 int scull_release(struct inode *inode,struct file *filp)
 {
    return 0;
 
 }
 
 struct file_operations fops={
    .owner =THIS_MODULE,
    .llseek = scull_llseek,
    .read   = scull_read,
    .write  = scull_write,
   .unlocked_ioctl  = scull_ioctl,
    .open   = scull_open,
    .release= scull_release,
    };
 
 
dev_t dev_num=MKDEV(SCULL_MAJOR,SCULL_MINOR);
static int hello_init(void)
{
    int result;
    printk(KERN_ALERT "hello,world");
    if(SCULL_MAJOR)
       	result=register_chrdev_region(dev_num,4,"scull");
    else 
        result=alloc_chrdev_region(&dev_num,SCULL_MINOR,4,"scull");
    if(result != 0){
        printk("scull register dev number fail \n");   
        return result;
     }
     
     
     
     
    
    return 0;
}


static void hello_exit(void)
{
    unregister_chrdev_region(dev_num,4);
    printk(KERN_ALERT "bye,world");

}

module_init(hello_init);
module_exit(hello_exit);
