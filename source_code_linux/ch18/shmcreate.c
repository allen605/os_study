#include <stdio.h>
#include <sys/shm.h>
#include "common.h"

int main()
{
  int shmid;

  /* Create the shared memory segment using MY_SHM_ID */
  shmid = shmget( MY_SHM_ID, 4096, 0666 | IPC_CREAT );

  if ( shmid >= 0 ) {

    printf( "Created a shared memory segment %d\n", shmid );

  }

  return 0;
}
