#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

void* thread_task(void *args)
{
	printf("Running in thread_task() call\n");
	sleep(30);
}

int main()
{
	pthread_t t_id;
	int ret;

	printf("Process ID before creating of the thread : %d\n", getpid());

	//Creating new thread
	ret = pthread_create(&t_id, NULL, thread_task, NULL);
	if(ret==0) {
		printf("Thread created successfully\n");
	} else {
		printf("Thread creating failed\n");
	}

	// Waiting for the created thread to terminate
	pthread_join(t_id, NULL);
	printf("Thread terminated\n");

	return 0;
}

/*
compile command : gcc thread_example.c -o thread_example -lpthread
execute : ./thread_example

onen the other terminall and run command "ps -T -p <pid will get from about getpid() call>"
Ex: ps -T -p 27904
*/