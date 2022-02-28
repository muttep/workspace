#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exitFunc() {
	printf("Called process cleanup function : exitFunc()\n");

	return;
}

int main()
{
	atexit(exitFunc);
	printf("Hello from main()\n");

	//return 0;

	exit(0);		// It will do the cleanup process through exitFunc() call
	//_exit(0);		// It will return the controle back to kernel immediatly, without doing any cleanup activity.
}