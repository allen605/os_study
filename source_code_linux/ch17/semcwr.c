
#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include "common.h"

int main()
{
  int semid, ret;

  /* Get the semaphore with the id MY_SEM_ID */
  semid = semget( MY_SEM_ID, 1, 0 );

  if (semid >= 0) {

    /* Read the current semaphore count */
    ret = semctl( semid, 0, SETVAL, 6 );

    if (ret != -1) {

      printf( "semcrd: semaphore count updated.\n" );

    }

  }

  return 0;
}

