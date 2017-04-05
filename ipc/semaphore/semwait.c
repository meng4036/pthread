#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	sem_t *sem;
	int val;

	if (argc != 2) {
		fprintf(stderr, "Usage: semwait <name>\n");
		exit(EXIT_FAILURE);
	}
	sem = sem_open(argv[1], 0);
	sem_wait(sem);
	
	sem_getvalue(sem, &val);
	printf("PID %ld has semaphore. value = %d\n", (long)getpid(), val);

	pause();
	exit(0);
}
