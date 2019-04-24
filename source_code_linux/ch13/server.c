#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/un.h> //define the sockaddr_un structure
int num_reverse(int num);

int main()
{
	char *num;
    /* 断开之前的socket文件 */
    unlink("server_socket");

    int server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un server_addr;
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, "server_socket");

    bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if(listen(server_sockfd, 5)<0);
    {
        perror("Listen failed");
    }

    int client_sockfd;
    struct sockaddr_un client_addr;
    socklen_t len = sizeof(client_addr);

    while(1)
    {
        printf("server waiting:\n");
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &len);

        read(client_sockfd, &num, 4);
        printf("get an integer from client: %c\n", num);
        num=num+1;
        write(client_sockfd, &num, 4);

        close(client_sockfd);
    }

    return 0;
}

int num_reverse(int num)
{
   int S=0,sum=0;

   while(num)
   {
	   S=num%10;
	   sum=10*sum+S;
	   num = num / 10;
   }

   return sum;
}

