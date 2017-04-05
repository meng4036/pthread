#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	sem_t *sem;
	int val;

	if (argc != 2) {
		fprintf(stderr, "Usage: sempost <name>\n");
		exit(EXIT_FAILURE);
	}
	sem = sem_open(argv[1], 0);
	sem_post(sem);
	
	sem_getvalue(sem, &val);
	printf("value = %d\n", val);

	exit(0);
}
