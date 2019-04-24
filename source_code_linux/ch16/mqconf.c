
#include <stdio.h>
#include <sys/msg.h>
#include "common.h"

int main()
{
  int msgid, ret;
  struct msqid_ds buf;

  /* Get the message queue for the id MY_MQ_ID */
  msgid = msgget( MY_MQ_ID, 0 );

  /* Check successful completion of msgget */
  if (msgid >= 0) {

    ret = msgctl( msgid, IPC_STAT, &buf );

    buf.msg_qbytes = 4096;

    ret = msgctl( msgid, IPC_SET, &buf );

    if (ret == 0) {

      printf( "Size successfully changed for queue %d.\n", msgid );

    }

  }

  return 0;
}

