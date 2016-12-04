/* *File:user_test.c
   *Author:Vishal Chopra
   *Date:4 Dec 2016
   *Purpose: This file is to acess BeagleBoneBlack GPIO 

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	int fd;
	fd = open(argv[1], O_RDWR);
	if(fd == -1){
		fprintf(stderr, "%s:Open\n", strerror(errno));
		perror("open");
		return -1;
	}
	printf("Device is open with FD = %d\n", fd);
	return 0;
}
