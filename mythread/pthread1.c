#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *msg);

int main()
{
	pthread_t tid1, tid2;

	const char *msg1 = "Thread 1";
	const char *msg2 = "Thread 2";
	int iret1, iret2;

	iret1 = pthread_create(&tid1, NULL, print_message, (void *) msg1);
	if (iret1) {
		fprintf(stderr, "pthread_create error: %d\n",iret1);
		exit(EXIT_FAILURE);
	}


	iret2 = pthread_create(&tid2, NULL, print_message, (void *) msg2);
	if (iret2) {
		fprintf(stderr, "pthread_create error: %d\n",iret2);
		exit(EXIT_FAILURE);
	}

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	exit(EXIT_SUCCESS);
}

void *print_message(void *ptr)
{
	char *message;
	message = (char *)ptr;
	printf("%s \n", message);
}
