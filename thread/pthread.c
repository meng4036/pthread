#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_func( void *ptr );

int main()
{
	pthread_t thread1, thread2;
	const char *msg1 = "Thread 1";
	const char *msg2 = "Thread 2";
	int ret1, ret2;

	ret1 = pthread_create( &thread1, NULL, print_message_func, (void *)msg1);
	if (ret1) {
		fprintf(stderr, "Pthread_create return value: %d\n", ret1);
		exit(EXIT_FAILURE);
	}
	ret2 = pthread_create( &thread2, NULL, print_message_func, (void *)msg2);
	if (ret2) {
		fprintf(stderr, "Pthread_create return value: %d\n", ret2);
		exit(EXIT_FAILURE);
	}

	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);

	exit(EXIT_SUCCESS);
}

void * print_message_func( void *ptr )
{
	char *msg;

	msg = (char *)ptr;
	fprintf(stdout, "%s \n", msg);
}
