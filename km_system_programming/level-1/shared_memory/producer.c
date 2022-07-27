#include <stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include <fcntl.h>           
#include <sys/stat.h>        
#include <semaphore.h>


int main()
{
       int shmid;
      char *msg;
     sem_unlink("name1");
    sem_unlink("name2");
    sem_t *sem_1,*sem_2;
    sem_1 = sem_open("name1",O_CREAT,0666,1);
    sem_2 = sem_open("name2",O_CREAT,0666,0); 

      if((shmid=shmget(10,1024,0666|IPC_CREAT))==-1) {
              perror("shmget");
              exit(1);
      }

      msg=shmat(shmid,0,0);
     
      while(1)
      {
        sem_wait(sem_1);
        printf("Enter the data you want to write into shared memory\n");
        fgets(msg,1024,stdin);

        printf("Data successfully written\n");
        sem_post(sem_2);
      }
      shmdt(msg);
}