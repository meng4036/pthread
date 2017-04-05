#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

#define FILE_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP

int main(int argc, char *argv[])
{
	int c, flags;
	sem_t *sem;
	unsigned int value;

	flags = O_RDWR | O_CREAT;
	value = 1;

	while ( (c = getopt(argc, argv, "ei:*")) != -1) {
		switch(c) {
		case 'e':
			flags != O_EXCL;
			break;
		case 'i':
			value = atoi(optarg);
			break;
		}
	}
	if (optind != argc - 1)
		fprintf(stderr, "Usage: semcreate [-e] [-i initalvalue] <name>\n");
	
	sem = sem_open(argv[optind], flags, FILE_MODE, value);
	sem_close(sem);
	
	exit(0);
}
