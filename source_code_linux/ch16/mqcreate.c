
#include <stdio.h>
#include <sys/msg.h>
#include "common.h"

int main()
{
  int msgid;

  /* Create the message queue with the id MY_MQ_ID */
  msgid = msgget( MY_MQ_ID, 0666 | IPC_CREAT );

  if (msgid >= 0) {

    printf( "Created a Message Queue %d\n", msgid );

  }

  return 0;
}

