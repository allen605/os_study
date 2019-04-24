#include <stdio.h>
#include <sys/shm.h>
#include <errno.h>
#include <time.h>
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

      printf("old permissions were 0%o\n", shmds.shm_perm.mode );

      shmds.shm_perm.mode = 0444;

      ret = shmctl( shmid, IPC_SET, &shmds );

      ret = shmctl( shmid, IPC_STAT, &shmds );

      printf("new permissions were 0%o\n", shmds.shm_perm.mode );

      ret = shmctl( shmid, SHM_LOCK, 0 );

      ret = shmctl( shmid, SHM_UNLOCK, 0 );

    } else {

      printf( "shmctl failed (%d)\n", errno );

    }

  } else {

    printf( "Shared memory segment not found.\n" );

  }

  return 0;
}
