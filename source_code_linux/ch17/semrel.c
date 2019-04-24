
#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include "common.h"

int main()
{
  int semid;
  struct sembuf sb;

  /* Get the semaphore with the id MY_SEM_ID */
  semid = semget( MY_SEM_ID, 1, 0 );

  if (semid >= 0) {

    printf( "semrel: Releasing semaphore %d\n", semid );

    sb.sem_num = 0;
    sb.sem_op  = 1;
    sb.sem_flg = 0;

    /* Release the semaphore */
    if (semop( semid, &sb, 1 ) == -1) {

      printf("semrel: semop failed.\n");
      exit(-1);

    }

    printf( "semrel: Semaphore released %d\n", semid );

  }

  return 0;
}

