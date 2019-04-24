#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include "common.h"

int main()
{
  int shmid, ret;
  void *mem;

  /* Get the shared memory segment using MY_SHM_ID */
  shmid = shmget( MY_SHM_ID, 0, 0 );

  mem = shmat( shmid, (const void *)0, 0 );

  printf( "%s", (char *)mem );

  ret = shmdt( mem );

  return 0;
}

