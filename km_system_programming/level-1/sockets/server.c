#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

#define LENGTH 100

void* S_Tx_thread(void *arg);
void* S_Rx_thread(void *arg);

int main()
{
    int res;

    int server_fd,client_fd;
    
    int server_len,client_len;

    struct sockaddr_in server_add;
    struct sockaddr_in client_add;


    server_fd = socket( AF_INET,SOCK_STREAM,0);
    if(server_fd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_add.sin_family = AF_INET;
    server_add.sin_addr.s_addr = INADDR_ANY;
    server_add.sin_port = 9734;
    
    server_len = sizeof(server_add);

    res = bind(server_fd,(struct sockaddr *)&server_add,server_len);
     if(res == -1)
     {
        perror("bind");
        exit(EXIT_FAILURE);
     }
     else
      printf("Bind success\n");

    res = listen(server_fd,5);
     if(res == -1)
     {
        perror("listen");
        exit(EXIT_FAILURE);
     }
     else
      printf("Listen success\n");


    printf("Server waiting\n");

    client_len = sizeof(client_add);
    client_fd = accept(server_fd,(struct sockaddr *)&client_add, &client_len);
    if(client_fd == -1)
    {
        perror("Accept");
        exit(EXIT_FAILURE);
    }
    else
      printf("Accept success\n");

    // Create threads

     pthread_t s_transmitter,s_receiver;
    res = pthread_create(&s_transmitter,NULL,S_Tx_thread,&client_fd);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&s_receiver,NULL,S_Rx_thread,&client_fd);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    // Threads creation completed


    res = pthread_join(s_transmitter, NULL);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

     res = pthread_join(s_receiver, NULL);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    close(client_fd);
     
}

void* S_Tx_thread(void *arg)
{
  char Tx_buff[LENGTH];
  while(1)
  {
  
  fgets(Tx_buff,LENGTH, stdin);
  write((int)arg, Tx_buff, sizeof(Tx_buff));

  if(strcmp(Tx_buff,"exit")==0)
     {
      printf("Byee");
      exit(0);
     }

  bzero(Tx_buff,sizeof(Tx_buff));

  }
}

void* S_Rx_thread(void* arg)
{
   char Rx_buff[LENGTH];
   while(1)
   {
     read((int)arg, Rx_buff, sizeof(Rx_buff));

     if(strcmp(Rx_buff,"exit")==0)
     {
      printf("Byee");
      exit(0);
     }

     printf("\t%s",Rx_buff);
     bzero(Rx_buff,sizeof(Rx_buff));
   }
}
