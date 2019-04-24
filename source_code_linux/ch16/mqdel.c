
#include <stdio.h>
#include <sys/msg.h>
#include "common.h"

int main()
{
  int   msgid, ret;

  msgid = msgget( MY_MQ_ID, 0 );

  if (msgid >= 0) {

    /* Remove the message queue */
    ret = msgctl( msgid, IPC_RMID, NULL );

    if (ret != -1) {

      printf( "Queue %d successfully removed.\n", msgid );

    }

  }

  return 0;
}

