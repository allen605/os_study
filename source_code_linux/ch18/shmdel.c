#include <stdio.h>
#include <sys/shm.h>
#include <errno.h>
#include "common.h"

int main()
{
  int shmid, ret;

  /* Create the shared memory segment using MY_SHM_ID */
  shmid = shmget( MY_SHM_ID, 0, 0 );

  if ( shmid >= 0 ) {

    ret = shmctl( shmid, IPC_RMID, 0 );

    if (ret == 0) {

      printf( "Shared memory segment removed\n" );

    } else {

      printf( "shmctl failed (%d)\n", errno );

    }

  } else {

    printf( "Shared memory segment not found.\n" );

  }

  return 0;
}
