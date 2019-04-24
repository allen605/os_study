#include <unistd.h>
#include <signal.h>
#include <stdio.h>
int pid1,pid2; 
main( )
{ 
int fd[2];
char outpipe[100],inpipe[100];
pipe(fd);                          /*����һ���ܵ�*/
while ((pid1=fork( )) == -1);
if(pid1 == 0)
{   lockf(fd[1],1,0);
/*���������������outpipe��*/
sprintf(outpipe,"child 1 process is sending message!"); 
write(fd[1],outpipe,50);     /*��ܵ�д��Ϊ50�ֽڵĴ�*/
sleep(3);                 /*��������3��*/
lockf(fd[1],0,0);
return 0;
}
else
{
while((pid2=fork( ))==-1);
if(pid2==0)
{   lockf(fd[1],1,0);           /*����*/
sprintf(outpipe,"child 2 process is sending message!");
write(fd[1],outpipe,50);
sleep(3);
lockf(fd[1],0,0);
return 0;
}
else
{   wait(0);              /*ͬ��*/
read(fd[0],inpipe,50);   /*�ӹܵ��ж���Ϊ50�ֽڵĴ�*/
printf("%s\n",inpipe);
wait(0);
read(fd[0],inpipe,50);
printf("%s\n",inpipe);
return 0;
}
}
}