#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	mqd_t mqd;
	struct mq_attr attr;
	
	if (argc != 2) {
		printf("Uage: create <name>\n");
		exit(EXIT_FAILURE);
	}

	mqd = mq_open(argv[1], O_RDWR | O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	if (mqd != -1) {
		mq_getattr(mqd, &attr);
		printf("megs = %ld\n", attr.mq_maxmsg);
		printf("bytes = %ld\n", attr.mq_msgsize);
	}

	mq_close(mqd);
}

