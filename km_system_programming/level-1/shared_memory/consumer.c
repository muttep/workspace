#include <stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include <fcntl.h>           
#include <sys/stat.h>        
#include <semaphore.h>
#include  <unistd.h>

int main()
{
      int shmid;
      char *msg;
    //sem_unlink("name1");
    //sem_unlink("name2");
    sem_t *sem_1,*sem_2;
    sem_1 = sem_open("name1",O_CREAT,0666,1);
    sem_2 = sem_open("name2",O_CREAT,0666,0); 

      if((shmid=shmget(10,1024,0))==-1) {
              perror("shmget");
              exit(1);
      }

      msg=shmat(shmid,0,0);

      while(1)
      {  
         sem_wait(sem_2);
         printf("Data written in the shared memory is:%s\n",msg);
         sem_post(sem_1);
      }
      
      shmdt(msg);
}