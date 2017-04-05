#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

int main()
{
	pthread_t thread[100];
	int ret;
	int i;

	for(i = 0; i < 100; i++) {
		ret = pthread_create(&thread[i], NULL, func, NULL);
		if (ret) {
			fprintf(stderr, "Create thread %d failed\n", i);
			exit(EXIT_FAILURE);
		}
	} 
	
	for(i = 0; i < 100; i++) {
		pthread_join(thread[i], NULL);
	}

	exit(EXIT_SUCCESS);
}

void *func()
{
	//pthread_mutex_lock(&mutex1);
	count++;
	printf("counter: %d\n", count);
	//pthread_mutex_unlock(&mutex1);
}
