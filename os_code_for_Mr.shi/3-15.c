//经典的生产者/消费者问题

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

pthread_mutex_t lock_it=PTHREAD_MUTEX_INITIALIZER; //初始化互斥锁
pthread_cond_t write_it =PTHREAD_COND_INITIALIZER;  //初始化条件变量  

typedef struct{
	    char buffer[MAX];
	    int how_many;
}BUFFER;

BUFFER share={"",0};

char ch='A';              //初始化ch

void *read_some(void *);
void *write_some(void *); 

int main(void)
{
	pthread_t t_read;
	pthread_t t_write; 

	pthread_create(&t_read,NULL,read_some,(void *)NULL);     /*创建生产者线程*/
	pthread_create(&t_write,NULL,write_some,(void *)NULL);    /*创建消费者线程*/

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
		pthread_mutex_lock(&lock_it);               //锁住互斥量
		if(share.how_many!=MAX)
		{
			share.buffer[share.how_many++]=ch++;//把字母读入缓存
			printf("R %2d:Got char[%c]\n",pthread_self(),ch-1);// 打印读入字母
			if(share.how_many==MAX)
			{
				printf("R %2d:signaling full\n",pthread_self());
				//如果缓存中的字母到达了最大值就发送信号
				pthread_cond_signal(&write_it);
			}
		}
		pthread_mutex_unlock(&lock_it);//解锁互斥量
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

		pthread_mutex_lock(&lock_it);        // 锁住互斥量
		printf("\nW %2d:Waiting\n",pthread_self());
		while(share.how_many!=MAX)      //如果缓存区字母不等于最大值就等待
			pthread_cond_wait(&write_it,&lock_it);
		printf("W %2d:writing buffer\n",pthread_self());
		for(i=0;share.buffer[i] && share.how_many; ++i,share.how_many--)
			putchar(share.buffer[i]);        //循环输出缓存区字母
		pthread_mutex_unlock(&lock_it);     // 解锁互斥量
	}
	printf("W %2d:exiting\n",pthread_self());
	return NULL;
}
