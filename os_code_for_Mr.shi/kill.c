#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int alarm_fired = 0;            //����δ����
//ģ������
void ding(int sig)
{
	alarm_fired = 1;               //��������
}

int main()
{
	int pid;

	printf("alarm application starting\n");
	if((pid = fork( )) == 0) 
	{     //�ӽ���5������ź�SIGALRM��������
		sleep(5);
		kill(getppid(), SIGALRM);
		//exit(0);
return 0;
	}
//�����̰��źò�׽��SIGALRM�źź�ִ��ding����
	printf("waiting for alarm to go off\n");
	(void) signal(SIGALRM, ding); 
	pause();           //���𸸽��̣�ֱ����һ���źų���
	if (alarm_fired)
		printf("Ding!\n");
	printf("done\n");
	//exit(0);
return 0;
}
