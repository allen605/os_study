#include <stdio.h>
#include <sys/shm.h>
#include <errno.h>
#include "common.h"

int main()
{
  int shmid, ret;
  void *mem;

  /* Get the shared memory segment using MY_SHM_ID */
  shmid = shmget( MY_SHM_ID, 0, 0 );

  if ( shmid >= 0 ) {

    mem = shmat( shmid, (const void *)0, 0 );

    if ( (int)mem != -1 ) {

      printf( "Shared memory was attached in our address space at %p\n", mem );

      ret = shmdt( mem );

      if (ret == 0) {

        printf("Successfully detached memory\n");

      } else {

        printf("Memory detached Failed (%d)\n", errno);

      }

    } else {

      printf( "shmat failed (%d)\n", errno );

    }

  } else {

    printf( "Shared memory segment not found.\n" );

  }

  return 0;
}
