#include "header.h"
#include "declaraction.h"
#include "ioctl_driver.h"


static long bbbgpio_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
	struct bbbgpio_ioctl_struct *ioctl_user_struct, ioctl_struct;
	
	memset(&ioctl_struct, 0, sizeof(struct bbbgpio_ioctl_struct));

	ioctl_user_struct = (struct bbbgpio_ioctl_struct *)ioctl_param;
	if( copy_from_user(&ioctl_struct, ioctl_user_struct, sizeof( struct bbbgpio_ioctl_struct ) ) ){
		
	}	
}
