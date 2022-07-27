/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>

#define LENGTH 100

void* C_Tx_thread(void *arg);
void* C_Rx_thread(void *arg);

int main()
{
    int len;
    struct sockaddr_in address;
    int result;

/*  Create a socket for the client.  */
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
/*  Name the socket, as agreed with the server.  */

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9734;
    len = sizeof(address);

/*  Now connect our socket to the server's socket.  */

    result = connect(sockfd, (struct sockaddr *)&address, len);

    if(result == -1) {
        perror("oops: client1");
        exit(1);
    }

    //Thread creation
     
    int res;
     pthread_t c_transmitter,c_receiver;
    res = pthread_create(&c_transmitter,NULL,C_Tx_thread,&sockfd);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&c_receiver,NULL,C_Rx_thread,&sockfd);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    //Threads creation completed

     res = pthread_join(c_transmitter, NULL);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

     res = pthread_join(c_receiver, NULL);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
   
   close(sockfd);
}

void* C_Tx_thread(void *arg)
{
    unsigned int n;
    char Tx_buff[LENGTH];
  while(1)
  {
     n = read(0,Tx_buff,LENGTH);
     write(*(int *)arg, Tx_buff,n);

     if(strcmp(Tx_buff,"exit")==0)
     {
      printf("Byee");
      exit(0);
     }

     bzero(Tx_buff,sizeof(Tx_buff));
  }
}

void* C_Rx_thread(void* arg)
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
