#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: semunlink <name>\n");
	}
	sem_unlink(argv[1]);

	exit(0);
}
