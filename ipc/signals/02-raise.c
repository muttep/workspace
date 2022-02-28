#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_catch_func(int sig)
{
	printf("Catch the signal\n");
}


int main()
{
	int ret;

	ret = signal(SIGINT, signal_catch_func);
	if(ret==SIG_ERR) {
		printf("Unable to register teh signal handler\n");
		exit(1);
	}

	printf("Going to raise the signal\n");
	ret=raise(SIGINT);
	if(ret!=0) {
		printf("Unable to raise the SIGINT signal\n");
		exit(1);
	}

	printf("Exiting...!");

	return 0;
}