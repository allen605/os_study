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

      printf( "Size of memory segment is %d\n", shmds.shm_segsz );
      printf( "Number of attaches %d\n", (int)shmds.shm_nattch );
      printf( "Create time %s", ctime( &shmds.shm_ctime ) );
      if (shmds.shm_atime) {
        printf( "Last attach time %s", ctime( &shmds.shm_atime ) );
      }
      if (shmds.shm_dtime) {
        printf( "Last detach time %s", ctime( &shmds.shm_dtime ) );
      }
      printf( "Segment creation user %d\n", shmds.shm_cpid );
      if (shmds.shm_lpid) {
        printf( "Last segment user %d\n", shmds.shm_lpid );
      }
      printf( "Access permissions 0%o\n", shmds.shm_perm.mode );


    } else {

      printf( "shmctl failed (%d)\n", errno );

    }

  } else {

    printf( "Shared memory segment not found.\n" );

  }

  return 0;
}
