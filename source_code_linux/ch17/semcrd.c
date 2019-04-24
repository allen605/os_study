
#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include "common.h"

int main()
{
  int semid, cnt;

  /* Get the semaphore with the id MY_SEM_ID */
  semid = semget( MY_SEM_ID, 1, 0 );

  if (semid >= 0) {

    /* Read the current semaphore count */
    cnt = semctl( semid, 0, GETVAL );

    if (cnt != -1) {

      printf("semcrd: current semaphore count %d.\n", cnt);

    }

  }

  return 0;
}

