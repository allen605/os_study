//经典的生产者/消费者问题

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
pthread_mutex_t lock_it=PTHREAD_MUTEX_INITIALIZER; //初始化互斥锁
pthread_cond_t write_it =PTHREAD_COND_INITIALIZER;  //初始化条件变量  
typedef struct buf{
	    char buffer[MAX];
	    int how_many;
}BUFFER;
BUFFER share={"",0};
char ch='A';              //初始化ch

void *read_some(void *junk)
{
	int n=0;
	printf("R %2d: starting\n",(int)pthread_self());
	while(ch!= 'U'){
		pthread_mutex_lock(&lock_it);	//上锁
		if(share.how_many!=MAX){
			share.buffer[share.how_many++]=ch++;	//把字母读入缓存
			printf("R:Got char[%c]\n",ch-1);	// 打印读入字母
			
			if(share.how_many==MAX){	//如果缓存中的字母到达了最大值就发送信号
				printf("R:full\n");
				sleep(6);
				pthread_cond_signal(&write_it);
			}
		}
		pthread_mutex_unlock(&lock_it);	//解锁
	} 
	printf("R %2d:Exiting\n",(int)pthread_self());
	return NULL;
}

void *write_some(void *junk)
{
	int i;
	int n=0;
	printf("w %2d: starting\n",(int)pthread_self());
	while(ch!='U'){
		pthread_mutex_lock(&lock_it);
		printf("\nW :Waiting\n");

		while(share.how_many!=MAX)      //如果缓存区字母不等于最大值就等待
			pthread_cond_wait(&write_it,&lock_it);

		printf("W :writing buffer\n");
		for(i=0;share.buffer[i] && share.how_many; ++i,share.how_many--){
			putchar(share.buffer[i]);        //循环输出缓存区字母
		}
		printf("\nW :writing done\n");
		sleep(4);
		pthread_mutex_unlock(&lock_it);     // 解锁互斥量
	}
	printf("W %2d:exiting\n",(int)pthread_self());
	return NULL;
}

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
