//经典的生产者/消费者问题
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 5 

pthread_mutex_t lock_it=PTHREAD_MUTEX_INITIALIZER; //初始化互斥锁
pthread_cond_t write_it =PTHREAD_COND_INITIALIZER;  //初始化条件变量  

typedef struct{
	char buffer[MAX];
	int how_many;
}BUFFER;

BUFFER share={"",0};	//初始化缓存区
char ch='A';        //初始化ch

void *read_some(void *junk)
{
	int n=0;
	printf("R %2d: starting\n",(int)pthread_self());
	while(ch!= 'Z'){
		pthread_mutex_lock(&lock_it);
		if(share.how_many!=MAX){
			share.buffer[share.how_many++]=ch++;//把字母读入缓存
			printf("R :Got char[%c]\n",ch-1);// 打印读入字母

			if(share.how_many==MAX){
				printf("R :signaling full\n");
				pthread_cond_signal(&write_it);//如果缓存中的字母到达了最大值就发送信号
			}
		}
		pthread_mutex_unlock(&lock_it);
	} 
	sleep(1);
	printf("R %2d:Exiting\n",(int)pthread_self());
	return NULL;
}

/*
当write线程抢到锁后，会去判断缓冲区是否已满，如果没满，则调用wait进入阻塞态并自动释放锁，此时read线程会去抢占锁并把字母读入缓冲区,当缓冲区满了时发送信号给write线程并解锁。write线程收到信号后自动上锁，继续运行while来判断缓冲区。如果缓冲区已满，则不会执行while循环里的wait函数，直接开始写数据，写完后清空缓冲区并解锁。一旦又一次被write抢到了锁，之后步骤和上面一样。
*/
void *write_some(void *junk)
{
	int i;
	int n=0;
	printf("w %2d: starting\n",(int)pthread_self());
	while(ch!='Z'){
		pthread_mutex_lock(&lock_it);
		
		while(share.how_many!=MAX){
			printf("\nW : waitting\n");
			pthread_cond_wait(&write_it,&lock_it);//等待中...(进入阻塞并解锁,当收到read线程的信号后，开始进入运行态并重新获得互斥锁，继续执行while（判断缓冲区是否已满）。
		}
		printf("W : start write:");
		for(i=0;share.buffer[i] && share.how_many; ++i,share.how_many--){
			putchar(share.buffer[i]);        //循环输出缓存区字母，并清除how_many
		}
		pthread_mutex_unlock(&lock_it);
	}
	printf("\nW %2d:exiting\n",(int)pthread_self());
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

