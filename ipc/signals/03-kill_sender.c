#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int main()
{
	kill(63726, SIGUSR1);
	scanf("\n");

	return 0;
}

/*
1. run the kill_sender binary from 1st terminal
2. from 2nd terminal run the command "ps -a". Observ the below output.
   PID TTY          TIME CMD
 63726 pts/1    00:00:00 03-kill_recv
 63739 pts/17   00:00:00 ps

3. updated the 1st argument of kill call above with the PID 63726 of kill_recv
4. Observ in the 1st terminal. Output is "Signal [10] received"

*/