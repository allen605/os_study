

void *PrintThread(void * num)
{
	int i;

	pthread_mutex_lock(&TestMutex);
	for(i = 0;i < 5; i++)
		{
		printf("thread number is %d\n",*((int *)num));
		sleep(1);
		}
	pthread_mutex_unlock(&TestMutex);
	return NULL;
}
#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
int total_words = 0;

pthread_mutex_t TestMutex = PTHREAD_MUTEX_INITIALIZER;

main(int ac , char * av[])
{
	pthread_t t1, t2;
	void *count_words(void *);
	if(ac!=3){
		printf("usage: %s file1 file2\n", av[0]);
		//exit(1);
		return;
	}
	 pthread_create(&t1,NULL,count_words,(void * ) av[1]);
	 pthread_create(&t2,NULL,count_words,(void * ) av[2]);
	 pthread_join(t1, NULL);
	 pthread_join(t2, NULL);
	 printf("%5d: total words\n", total_words);
}
void *count_words(void *f)
{
	char *filename = (char * )f;
	FILE *fp;
	int c, temp, prevc = '\0';
	
	if((fp = fopen (filename, "r" )) != NULL)
	{
		while((c = getc(fp))!= EOF)
		{
		  if(!isalnum(c)&& isalnum(prevc))
			{
				temp=total_words;
				sleep(1);                          /*延时，使产生脏数据*/
				total_words=temp+1;
			}			
		prevc =c;
		}
	fclose(fp);
	} 
	else
		printf("err filename");
	return NULL;
}
