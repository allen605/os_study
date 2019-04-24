#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/un.h>

#define MAX_BUFFER              128
#define DAYTIME_SERVER_PORT     10086
#define DAYTIME_CLIENT_PORT     1025

int main (int argc,char *argv[])
{
  int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
  printf("client begin\n");
  
  struct sockaddr_un address;
  address.sun_family = AF_UNIX;
  strcpy(address.sun_path, "server_socket");

  /*从键盘读取需要转置的整数*/
  char *num = argv[1];
  printf("Please enter the num to reverse:%s %s %s\n",num,argv[0], argv[1]);

  int result = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
  if(result == -1)
  {
	  printf("connect failed\n");
	  return 0;
  }
  printf("connected.\n");

  write(sockfd, num, 4);//一个int 4个字节
  read(sockfd, num, 4);
  printf("get an integer from server: %s\n", num);

  close(sockfd);
  return 0;
}

