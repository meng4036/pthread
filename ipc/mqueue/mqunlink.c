#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Uage: unlink <name>\n");
		exit(EXIT_FAILURE);
	}
	
	mq_unlink(argv[1]);
}

