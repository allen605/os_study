//�����������/����������

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

pthread_mutex_t lock_it=PTHREAD_MUTEX_INITIALIZER; //��ʼ��������
pthread_cond_t write_it =PTHREAD_COND_INITIALIZER;  //��ʼ����������  

typedef struct{
	    char buffer[MAX];
	    int how_many;
}BUFFER;

BUFFER share={"",0};

char ch='A';              //��ʼ��ch

void *read_some(void *);
void *write_some(void *); 

int main(void)
{
	pthread_t t_read;
	pthread_t t_write; 

	pthread_create(&t_read,NULL,read_some,(void *)NULL);     /*�����������߳�*/
	pthread_create(&t_write,NULL,write_some,(void *)NULL);    /*�����������߳�*/

	pthread_join(t_write,(void **)NULL);

	pthread_mutex_destroy(&lock_it);
	pthread_cond_destroy(&write_it);
	exit(0);
}

void *read_some(void *junk)
{
	int n=0;
	printf("R %2d: starting\n",pthread_self());
	while(ch!= 'Z')
	{
		pthread_mutex_lock(&lock_it);               //��ס������
		if(share.how_many!=MAX)
		{
			share.buffer[share.how_many++]=ch++;//����ĸ���뻺��
			printf("R %2d:Got char[%c]\n",pthread_self(),ch-1);// ��ӡ������ĸ
			if(share.how_many==MAX)
			{
				printf("R %2d:signaling full\n",pthread_self());
				//��������е���ĸ���������ֵ�ͷ����ź�
				pthread_cond_signal(&write_it);
			}
		}
		pthread_mutex_unlock(&lock_it);//����������
	} 
	sleep(1);
	printf("R %2d:Exiting\n",pthread_self());
	return NULL;
}

void *write_some(void *junk)
{
	int i;
	int n=0;
	printf("w %2d: starting\n",pthread_self());
	while(ch!='Z')
	{

		pthread_mutex_lock(&lock_it);        // ��ס������
		printf("\nW %2d:Waiting\n",pthread_self());
		while(share.how_many!=MAX)      //�����������ĸ���������ֵ�͵ȴ�
			pthread_cond_wait(&write_it,&lock_it);
		printf("W %2d:writing buffer\n",pthread_self());
		for(i=0;share.buffer[i] && share.how_many; ++i,share.how_many--)
			putchar(share.buffer[i]);        //ѭ�������������ĸ
		pthread_mutex_unlock(&lock_it);     // ����������
	}
	printf("W %2d:exiting\n",pthread_self());
	return NULL;
}
