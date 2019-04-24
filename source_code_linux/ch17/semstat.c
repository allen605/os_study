
#include <stdio.h>
#include <sys/sem.h>
#include <time.h>
#include "common.h"

int main()
{
  int semid, ret;
  struct semid_ds sembuf;

  union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
  } arg;

  /* Get the semaphore with the id MY_SEM_ID */
  semid = semget( MY_SEM_ID, 1, 0 );

  if (semid >= 0) {

    arg.buf = &sembuf;
    ret = semctl( semid, 0, IPC_STAT, arg );

    if (ret != -1) {

      if (sembuf.sem_otime) {
        printf( "Last semop time %s", ctime( &sembuf.sem_otime ) );
      }

      printf( "Last change time %s", ctime( &sembuf.sem_ctime ) );

      printf( "Number of semaphores %ld\n", sembuf.sem_nsems );

      printf( "Owner's user id %d\n", sembuf.sem_perm.uid );
      printf( "Owner's group id %d\n", sembuf.sem_perm.gid );

      printf( "Creator's user id %d\n", sembuf.sem_perm.cuid );
      printf( "Creator's group id %d\n", sembuf.sem_perm.cgid );

      printf( "Permissions 0%o\n", sembuf.sem_perm.mode );

    }

  }

  return 0;
}

