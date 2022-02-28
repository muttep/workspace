#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t ret;

	printf("Process ID : %d\n", getpid());

	ret=fork();
	if(ret<0) {
		printf("fork() is failed\n");
	} else if(ret==0) {
		printf("Child process\n");
		printf("Child process ID : %d\n", getpid());
		sleep(20);
	} else {
		wait();		// To wait the Parent process untill chile gets terminated. Otherwise parent will get exit then child will be orphan
		printf("Parent process\n");
		printf("Parent process ID : %d\n", getpid());
		sleep(30);
	}

	return 0;
}