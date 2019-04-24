
#include <stdio.h>
#include <sys/sem.h>
#include "common.h"

int main()
{
  int semid;

  /* Create the semaphore with the id MY_SEM_ID */
  semid = semget( MY_SEM_ID, 1, 0666 | IPC_CREAT );

  if (semid >= 0) {

    printf( "semcreate: Created a semaphore %d\n", semid );

  }

  return 0;
}

