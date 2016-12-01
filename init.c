/** File: init.c
  * Author: Vishal Chopra
  * Date: 20Nov2016
  * Brief: This function is to initialize and register caharcter driver, mutex and gpio operations like open read write and release from the driver.
*/

#include "header.h"

dev_t bbb_dev;
struct bbbgpio_device *bbbgpio_device_Ptr = NULL;
static struct class *bbbclass_Ptr = NULL;

static int __init bbbgpio_init(void)
{
	driver_info("Driver initialization Start on %s at %s\n", __DATE__, __TIME__);
	
	if(alloc_chrdev_region(&bbb_dev, 0, 1, DRIVER_NAME) < 0){
		driver_err("%s could not register\n", DRIVER_NAME);
		goto failed_register;
	}

	bbbgpio_device_Ptr = kmalloc(sizeof(struct bbbgpio_device), GFP_KERNEL);
	if(bbbgpio_device_Ptr == NULL){
		driver_err("%s kmalloc fail\n", DRIVER_NAME);
		goto failed_alloc;
	}
	memset(bbbgpio_device_Ptr, 0, sizeof(struct bbbgpio_device));

	bbbclass_Ptr = class_create(THIS_MODULE, DEVICE_CLASS_NAME);
	if( IS_ERR(bbbclass_Ptr) ){
		driver_err("%s unable to create class\n", DRIVER_NAME);
		goto failed_class_create;
	}
	
	cdev_init(bbbgpio_device_Ptr->cdev, &fops);	//to initialize cdev structure
	bbbgpio_Ptr->cdev.owner = THIS_MODULE;
	if( cdev_add(&bbbgpio_Ptr->cdev, bbb_dev, 1) != 0){
		driver_err("%s Unable to add cdev structure\n");
		goto failed_cdev_add;
	}

	bbbgpio_device_Ptr->device = device_create(bbbclass_Ptr, NULL, MKDEV(MAJOR(bbb_dev)), NULL, DEVICE_PROCESS, 0);
	if(IS_ERR(bbbgpio_Ptr->device)){
		device_err("%s Unable to create device\n");
		goto failed_device_create;
	}

module_exit(bbbgpio_exit)
	driver_info("Driver initialization End\n");

failed_register:
	return 0;
failed_alloc:
	return -EBUSY;
failed_class_create:
{
	kfree(bbbgpio_device_ptr);
	unregister_chrdev_region(bbb_dev, 1);

}
faled_cdev_add:
{
	class_destroy(bbbgpio_device_ptr);
	kfree(bbbgpio_device_ptr);
	unregister_chrdev_region(bbb_dev, 1);
		
}
faled_cdev_add:
{
	device_destroy(bbbclass_Ptr, MKDEV(MAJOR(bbb_dev), 0));
	class_destroy(bbbgpio_device_ptr);
	kfree(bbbgpio_device_ptr);
	unregister_chrdev_region(bbb_dev, 1);
		
}
	return 0;
}

module_init(bbbgpio_init)
