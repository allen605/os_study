/*************************************************************************
	> File Name: system.c
	> Author: garen
	> Mail: xiaoyuering@163.com 
	> Created Time: 2019年03月24日 星期日 09时27分49秒
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int system(const char *cmdstring){
    pid_t pid;
    int status;

    int ret;
    if(cmdstring==NULL)
        return 0;
	if((pid=fork()) < 0){
		return -1;
	}
	else if(pid==0){
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
		puts("don't execute here.");
		exit(127);
	}
	else{
		int ret=waitpid(pid,&status,0);
		printf("ret:%d\n",ret);
		while(ret < 0){
			if(errno!=EINTR){
				status = -1;
				break;
			}
		}
		puts("done.");
	}
	return status;
}

int main(int argc, char **argv)
{
	puts("start system...");
	int ret=system("uname -a");
	printf("ret:%d\n",ret);
	exit(0);
}
