// https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t tid[2];
int counter;

#if 0
void* tryThis(void *arg)
{	
	unsigned long i=0;
	counter += 1;

	printf("Thread %d is started\n", counter);

	for (i = 0; i < (0xFFFFFFFF); i++);

	printf("Thread %d is finished\n", counter);

	return 0;
}

int main()
{
	int i=0;
	int ret;

	while(i<2) {
		ret=pthread_create(&tid[i], NULL, &tryThis, NULL);
		if(ret != 0) {
			printf("Thread can not be created : [%s]\n", strerror(ret));
		}

		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}
#endif

/*
Thread 1 is started
Thread 2 is started
Thread 2 is finished
Thread 2 is finished

*/

/*
Why it has occurred ?
	On observing closely and visualizing the execution of the code, we can see that :

. The log ‘Job 2 has started’ is printed just after ‘Job 1 has Started’ so it can easily be concluded that while thread 1 was processing the scheduler scheduled the thread 2.
. If we take the above assumption true then the value of the ‘counter’ variable got incremented again before job 1 got finished.
. So, when Job 1 actually got finished, then the wrong value of counter produced the log ‘Job 2 has finished’ followed by the ‘Job 2 has finished’ for the actual job 2 or vice versa as it is dependent on scheduler.
. So we see that its not the repetitive log but the wrong value of the ‘counter’ variable that is the problem.
. The actual problem was the usage of the variable ‘counter’ by a second thread when the first thread was using or about to use it.
. In other words, we can say that lack of synchronization between the threads while using the shared resource ‘counter’ caused the problems or in one word we can say that this problem happened due to ‘Synchronization problem’ between two threads.

How to solve it ?
	The most popular way of achieving thread synchronization is by using Mutexes.
*/

// Solution with for the above race conditon below with Mutext lock

#include <pthread.h>

#if 1

pthread_mutex_t lock; 

void* tryThis(void *arg)
{		
	pthread_mutex_lock(&lock);

	unsigned long i=0;
	counter += 1;

	printf("Thread %d is started\n", counter);

	for (i = 0; i < (0xFFFFFFFF); i++);

	printf("Thread %d is finished\n", counter);

	pthread_mutex_unlock(&lock);

	return 0;
}

int main()
{
	int i=0;
	int ret;
	int ret_lock;

	ret_lock=pthread_mutex_init(&lock, NULL);
	if(ret_lock != 0) {
		printf("Mutext init is failed\n");
		return 1;
	}

	while(i<2) {
		ret=pthread_create(&tid[i], NULL, &tryThis, NULL);
		if(ret != 0) {
			printf("Thread can not be created : [%s]\n", strerror(ret));
		}

		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
#endif

/*
Thread 1 is started
Thread 1 is finished
Thread 2 is started
Thread 2 is finished

*/