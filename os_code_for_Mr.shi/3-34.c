#include <stdio.h>
#include <stdlib.h>
int main (void)
{
int i, k;
for (i=0; i<3; i++)
{
k=fork();
if (k==0)
break;
}
printf(¡°Counter=%d Pid=%d Parent pid=%d\n¡±, i, getpid(),getppid());
return 0;
}
