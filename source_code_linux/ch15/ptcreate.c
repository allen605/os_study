
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void *myThread( void *arg )
{
  pthread_t pt;

  pt = pthread_self();

  printf("Thread %x ran!\n", (int)pt );

  pthread_exit( NULL );
}


int main()
{
  int ret;
  pthread_t mythread;

  ret = pthread_create( &mythread, NULL, myThread, NULL );

  if (ret != 0) {
    printf( "Can't create pthread (%s)\n", strerror( errno ) );
    exit(-1);
  }

  return 0;
}

