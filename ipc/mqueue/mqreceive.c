#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>



int main(int argc, char *argv[])
{
	mqd_t mqd;
	struct mq_attr attr;
	void *ptr;
	ssize_t n;
	unsigned int prio;

	mqd = mq_open(argv[1], O_RDONLY);
	if (mqd != -1) {
		ptr = malloc(attr.mq_msgsize);
		n = mq_receive(mqd, ptr, attr.mq_msgsize, &prio);
		printf("Message: %s\n", ptr);
		printf("read %ld bytes, priority = %u\n", (long)n, prio );
		free(ptr);
	}

	mq_close(mqd);
}

