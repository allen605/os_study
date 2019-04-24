#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BUFFER              128
#define DAYTIME_SERVER_PORT     10086
#define DAYTIME_CLIENT_PORT     1025

int main ()
{
  int connectionFd, in, index = 0, limit = MAX_BUFFER, connectValue;
  struct sockaddr_in servaddr,cliaddr,tmpaddr;
  char timebuffer[MAX_BUFFER+1];
  printf("client begin\n");

  connectionFd = socket(AF_INET, SOCK_STREAM, 0);
  
  memset(&cliaddr, 0, sizeof(cliaddr));
  cliaddr.sin_family = AF_INET;
  cliaddr.sin_port = htons(DAYTIME_CLIENT_PORT);
  cliaddr.sin_addr.s_addr = inet_addr("127.0.0.123");//client ip


  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(DAYTIME_SERVER_PORT);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.110");//server ip
  
  bind(connectionFd,(struct sockaddr *)&cliaddr, sizeof(cliaddr) );
  
  connectValue=connect(connectionFd,(struct sockaddr *)&servaddr, sizeof(servaddr));
  printf("connect %d\n",connectValue);
  if(connectValue==0)
  {
    int ret=0,size;
    size = sizeof(tmpaddr);
  	ret=getsockname(connectionFd,(struct sockaddr *)&tmpaddr,&size );
  	if(ret>=0){
      printf("client ip:%s, port:%d\n",inet_ntoa(tmpaddr.sin_addr),ntohs(tmpaddr.sin_port));
    }
  }
  while ( (in = read(connectionFd, &timebuffer[index], limit)) > 0) {
    index += in;
    limit -= in;
  }

  timebuffer[index] = 0;
  printf("\n%s\n", timebuffer);

  close(connectionFd);

  return(0);
}

