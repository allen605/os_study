#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *PrintThread(void * );

#define Num_Threads 3

int main()
{
	int i,ret;
	pthread_t a_thread;
	int ThdNum[Num_Threads];

	for (i = 0; i < Num_Threads; i++)
		ThdNum[i] = i;

	for(i = 0; i < Num_Threads;i++)
	{
		ret = pthread_create(&a_thread,NULL,PrintThread,(void *)&ThdNum[i]);
		if (ret == 0)
			printf("Thread launched succeddfully\n");
	}
	i = getchar();
	return (0);
}

void *PrintThread(void * num)
{
	int i;

	for(i = 0;i < 5; i++)
		{
		printf("thread number is %d\n",*((int *)num));
		sleep(i);
		}
	return NULL;
}
