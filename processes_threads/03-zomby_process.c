#if 0
// A C program to demonstrate working of
// fork() and process table entries.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
 
int main()
{
    int i;
    int pid = fork();
 
    if (pid == 0)
    {
        for (i=0; i<20; i++)
            printf("I am Child\n");
    }
    else
    {
        printf("I am Parent\n");
        while(1);
    }
}
#endif

/*  // Output
I am Parent
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child
I am Child

*/

/* Run "ps -eaf" from other terminal

andu     38114  38106 99 22:07 ?        00:00:53 /home/pandu/workspace/processes_threads/03-zomby_process
pandu     38115  38114  0 22:07 ?        00:00:00 [03-zomby_proces] <defunct>
pandu     38134  27830 99 22:08 pts/1    00:00:15 ./03-zomby_process
pandu     38135  38134  0 22:08 pts/1    00:00:00 [03-zomby_proces] <defunct>           /// It is zomby process as it is defunct process. It exists in the process table even i exit
pandu     38137  27893  0 22:08 pts/17   00:00:00 ps -eaf

*/

// Zomby process solution

// A C program to demonstrate working of
// fork()/wait() and Zombie processes
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
 
int main()
{
    int i;
    int pid = fork();
    if (pid==0)
    {
        for (i=0; i<20; i++)
            printf("I am Child\n");
    }
    else
    {
        wait(NULL);
        printf("I am Parent\n");
        while(1);
    }
}

/* // output

pandu     38114  38106 99 22:07 ?        00:05:03 /home/pandu/workspace/processes_threads/03-zomby_process
pandu     38115  38114  0 22:07 ?        00:00:00 [03-zomby_proces] <defunct>
root      38138      2  0 22:08 ?        00:00:00 [kworker/u256:0]
pandu     38241  27830 99 22:12 pts/1    00:00:04 ./a.out
pandu     38243  27893  0 22:12 pts/17   00:00:00 ps -eaf

*/