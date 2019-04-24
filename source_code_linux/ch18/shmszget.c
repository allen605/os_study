#include <stdio.h>
#include <sys/shm.h>
#include <errno.h>
#include "common.h"

int main()
{
  int shmid, ret;
  struct shmid_ds shmds;

  /* Create the shared memory segment using MY_SHM_ID */
  shmid = shmget( MY_SHM_ID, 0, 0 );

  if ( shmid >= 0 ) {

    ret = shmctl( shmid, IPC_STAT, &shmds );

    if (ret == 0) {

      printf( "Size of memory segment is %d\n", shmds.shm_segsz );
      printf( "Number of attaches %d\n", (int)shmds.shm_nattch );

    } else {

      printf( "shmctl failed (%d)\n", errno );

    }

  } else {

    printf( "Shared memory segment not found.\n" );

  }

  return 0;
}
