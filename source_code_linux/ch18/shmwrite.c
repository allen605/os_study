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

  strcpy( (char *)mem, "This is a test string.\n" );

  ret = shmdt( mem );

  return 0;
}

