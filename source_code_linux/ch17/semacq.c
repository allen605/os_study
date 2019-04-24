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

    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = 0;

    printf( "semacq: Attempting to acquire semaphore %d\n", semid );

    /* Acquire the semaphore */
    if (semop( semid, &sb, 1 ) == -1) {

      printf("semacq: semop failed.\n");
      exit(-1);

    }

    printf( "semacq: Semaphore acquired %d\n", semid );

  }

  return 0;
}

