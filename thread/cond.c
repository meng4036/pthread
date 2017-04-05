#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *func1();
void *func2();
int count = 0;

#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

int main()
{
	pthread_t thread1, thread2;

	pthread_create( &thread1, NULL, func1, NULL);
	pthread_create( &thread2, NULL, func2, NULL);

	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);

	printf("Final count: %d\n", count);
	exit(EXIT_SUCCESS);
}

void *func1()
{
	for(;;) {
		pthread_mutex_lock( &count_mutex );
		pthread_cond_wait( &cond, &count_mutex );
		count ++;
		printf("Counter 1 value: %d\n", count);

		pthread_mutex_unlock( &count_mutex );
		if ( count >= COUNT_DONE) 
			return ;
	}
}

void *func2()
{
	for(;;) {
		pthread_mutex_lock( &count_mutex );
		if ( count < COUNT_HALT1 || count > COUNT_HALT2 ) {
			pthread_cond_signal( &cond );
		} else {
			count ++;
			printf("Counter 2 value: %d\n", count);
		}
		pthread_mutex_unlock( &count_mutex );
		if (count >= COUNT_DONE) 
			return ;
	}
}
