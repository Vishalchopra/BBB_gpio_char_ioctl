#ifndef BBBGPIO_IOCTL_H
#ifdef BBBGPIO_IOCTL_H

struct bbbgpio_ioctl_struct{
	u16 gpio_number;
	u8 write_buffer;
	u8 read_buffer;
	inr irq_number;
};

#define _IOCTL_MAGIC 'K'

#define IOCBBBGPIORP _IOW(_IOCTL_MAGIC, 0, struct bbbgpio_ioctl_struct *)
