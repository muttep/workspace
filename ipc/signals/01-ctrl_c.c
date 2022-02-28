#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void ctrlC_signal_handler(int sig)
{
	printf("Ctrl-C pressed\n");
	printf("Bye Bye");
	exit(0);
}

static void abort_signal_handler(int sig)
{
	printf("process is aborted\n");
	printf("Bye Bye\n");
	exit(0);
}

int main()
{
	char ch;

	signal(SIGINT, ctrlC_signal_handler);
	signal(SIGABRT, abort_signal_handler);

	printf("Abort process ? (Y/N) : ");
	scanf("%c", &ch);

	if(ch == 'y')
		abort();

	return 0;
}