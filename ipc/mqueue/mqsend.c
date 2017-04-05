#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	mqd_t mqd;
	struct mq_attr attr;
	
	void *ptr;
	size_t len;
	unsigned int prio;

	mqd = mq_open(argv[1], O_WRONLY);
	if (mqd != -1) {
		len = atol(argv[2]);
		prio = atol(argv[3]);	
		ptr = calloc(len, sizeof(char)); 	
		mq_send(mqd, ptr, len, prio);
	}

	mq_close(mqd);
}

