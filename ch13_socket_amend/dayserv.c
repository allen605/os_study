#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER		128
#define DAYTIME_SERVER_PORT	10086

int main ( void )
{
  int serverFd, connectionFd, size;
  struct sockaddr_in servaddr,tmpaddr;
  char timebuffer[MAX_BUFFER+1];
  time_t currentTime;
  printf("server begin.\n");

  serverFd = socket( AF_INET, SOCK_STREAM, 0 );

  memset( &servaddr, 0, sizeof(servaddr) );
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.110");
  servaddr.sin_port = htons(DAYTIME_SERVER_PORT);

  bind( serverFd,(struct sockaddr *)&servaddr, sizeof(servaddr) );

  listen( serverFd, 5 );
  printf("listen...\n");
  while ( 1 ) {
    connectionFd = accept( serverFd,(struct sockaddr *)NULL,NULL );
    if (connectionFd >= 0) {
      printf("connected\n");
      size = sizeof(tmpaddr);
      if(getsockname(serverFd,(struct sockaddr *)&tmpaddr, &size)>=0){
        printf("server ip:%s, port:%d\n", inet_ntoa(tmpaddr.sin_addr),ntohs(tmpaddr.sin_port));
      }
      currentTime = time(NULL);
      snprintf( timebuffer, MAX_BUFFER, "%s\n", ctime(&currentTime) );
      write( connectionFd, timebuffer, strlen(timebuffer) );
      close( connectionFd );
      printf("close.\n");
    }
  }
}

