#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int wait_mark;
void waiting( ),stop( );

void main( )
{
	int p1,p2;

	signal(SIGINT,stop);			
	while((p1=fork())==-1);
	if(p1>0) /*�����̵Ĵ���*/
	{ 
		while((p2=fork())==-1);
		/*�����̵Ĵ���*/
		if(p2>0)  
		{  
			wait_mark=1;
			/*�ȴ�����ctrl+c�ź�*/
			waiting( );
			/*��p1�����ź�16*/
			kill(p1,16);
			/*��p2�����ź�17*/
			kill(p2,17);
			/*ͬ��*/
			wait(0);
			wait(0);
			printf("parents is killed \n");
			//exit(0);
			return ;
		}
		else	 /*p2���̵Ĵ���*/
		{
			wait_mark=1;
			signal(17,stop);
			waiting();	/*�ȴ��ź�17*/
			sleep(1); 
			/*�������ķ���ʵ�ֻ���*/
			lockf((int)stdout,1,0);	
			printf("P2 is killed by parent \n");
			lockf((int)stdout,0,0);
		/*ģ��P2��killʱ���̵Ĺ���*/
			//exit(0);
			return ;
		}
	}
	else		/*p1���̵Ĵ���*/
	{
		wait_mark=1;
		signal(16,stop);
		waiting( ); /*�ȴ��ź�16*/
		sleep(1); 
		/*�������ķ���ʵ�ֻ���*/
		lockf((int)stdout,1,0);
		printf("P1 is killed by parent \n");
		lockf((int)stdout,0,0);
		/*ģ��P1��killʱ���̵Ĺ���*/
		//exit(0);	
		return;	
	}
}

void	waiting( )
{
	while(wait_mark!=0);
}

void	stop( )
{
	wait_mark=0;
}
