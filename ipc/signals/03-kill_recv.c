#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void signal_handler(int sig)
{
	printf("Signal [%d] received\n", sig);
}

int main()
{
	signal(SIGUSR1, signal_handler);
	scanf("\n");

	return 0;
}