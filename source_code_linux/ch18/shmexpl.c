#include <stdio.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

#define MAX_STRING	5000

typedef struct {
  int semID;
  int counter;
  char string[MAX_STRING+1];
  char user;
} MY_BLOCK_T;

int main( int argc, char *argv[] )
{
  int shmid, ret, i;
  MY_BLOCK_T *block;
  struct sembuf sb;
  char user;

  /* Make sure there's a command */
  if (argc >= 2) {

    /* Create the shared memory segment and init it with the semaphore */
    if (!strncmp( argv[1], "create", 6 )) {

      /* Create the shared memory segment and semaphore */

      printf("Creating the shared memory segment\n");

      /* Create the shared memory segment */
      shmid = shmget( MY_SHM_ID, sizeof(MY_BLOCK_T), (IPC_CREAT | 0666) );

      /* Attach to the segment */
      block = (MY_BLOCK_T *)shmat( shmid, (const void *)0, 0 );

      /* Initialize our write pointer */
      block->counter = 0;

      /* Create the semaphore */
      block->semID = semget( MY_SEM_ID, 1, (IPC_CREAT | 0666) );
      
      /* Increment the semaphore */
      sb.sem_num = 0;
      sb.sem_op = 1;
      sb.sem_flg = 0;
      semop( block->semID, &sb, 1 );

      /* Now, detach from the segment */
      shmdt( (void *)block );

    } else if (!strncmp( argv[1], "use", 3 )) {

      /* Use the segment */

      /* Must specify also a letter (to write to the buffer) */
      if (argc < 3) exit(-1);

      user = (char)argv[2][0];

      /* Grab the shared memory segment */
      shmid = shmget( MY_SHM_ID, 0, 0 );

      /* Attach to it */
      block = (MY_BLOCK_T *)shmat( shmid, (const void *)0, 0 );

      for (i = 0 ; i < 2500 ; i++) {

        /* Give up the CPU temporarily */
        sleep(0);

        /* Grab the semaphore */
        sb.sem_num = 0;
        sb.sem_op = -1;
        sb.sem_flg = 0;
        if ( semop( block->semID, &sb, 1 ) != -1 ) {

          /* Write our letter to the segment buffer 
           * (only if we have the semaphore).  This
           * is our critical section.
           */
          block->string[block->counter++] = user;

          /* Release the semaphore */
          sb.sem_num = 0;
          sb.sem_op = 1;
          sb.sem_flg = 0;
          if ( semop( block->semID, &sb, 1 ) == -1 ) {

            printf("Failed to release the semaphore\n");

          }

        } else {

          printf("Failed to acquire the semaphore\n");

        }

      }

      /* We're done, unmap the shared memory segment. */
      ret = shmdt( (void *)block );

    } else if (!strncmp( argv[1], "read", 6 )) {

      /* Here, we'll read the buffer in the shared segment */

      shmid = shmget( MY_SHM_ID, 0, 0 );

      if (shmid >= 0) {

        block = (MY_BLOCK_T *)shmat( shmid, (const void *)0, 0 );

        /* Terminate the buffer */
        block->string[block->counter+1] = 0;

        printf( "%s\n", block->string );

        printf("length %d\n", block->counter);

        ret = shmdt( (void *)block );

      } else {

        printf("Unable to read segment.\n");

      }

    } else if (!strncmp( argv[1], "remove", 6 )) {

      shmid = shmget( MY_SHM_ID, 0, 0 );

      if (shmid >= 0) {

        block = (MY_BLOCK_T *)shmat( shmid, (const void *)0, 0 );

        /* Remove the semaphore */
        ret = semctl( block->semID, 0, IPC_RMID );

        /* Remove the shared segment */
        ret = shmctl( shmid, IPC_RMID, 0 );

        if (ret == 0) {

          printf("Successfully removed the segment.\n");

        }

      }

    } else {

      printf( "Unknown command %s\n", argv[1] );

    }

  }
  
  return 0;
}

