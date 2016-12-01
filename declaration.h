/** File: declaration.h
  * AUTHOR: Vishal Chopra
  * DATE 20 NOV 2016
  * Brief: This file contain all the declaration of the variable.
*/

struct file_operations fops={
	
};

struct bbbgpio_device{
	struct cdev cdev;
	struct device *device_Ptr;
};

extern struct bbbgpio_device *bbbgpio_device_Ptr;
