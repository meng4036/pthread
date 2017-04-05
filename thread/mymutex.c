#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define ITEM_MAX 100

int items[ITEM_MAX];
int count;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *print(void *);


int main()
{
	pthread_t tids[ITEM_MAX];	
	int i = 0;
	int iret;

	for (i=0; i<ITEM_MAX; i++) {
		 iret = pthread_create(&tids[i], NULL, print, NULL);
		if (iret) {
			printf("Create thread error\n");
			exit(EXIT_FAILURE);
		}	
	}

	for (i=0; i<ITEM_MAX; i++) {
		pthread_join(tids[i], NULL);
	}
	exit(EXIT_SUCCESS);
}


void *print(void *tmp)
{
	//pthread_mutex_lock(&mutex);
	count ++; 
	printf("count = %d\n", count);
	//pthread_mutex_unlock(&mutex);
}
