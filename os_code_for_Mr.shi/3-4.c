#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
	printf("OUCH! - I got signal %d\n", sig);
	/*�ָ�SIGINT�źŵĴ�����*/
	(void) signal(SIGINT, SIG_DFL); 
}

int main()
{
	//����SIGINT�źŵĴ�����Ϊ��Ӧouch����
	(void) signal(SIGINT, ouch);  

	//������ÿ��1������ַ���
	while(1) {
		printf("Hello World!\n");
		sleep(1);
	}
}
