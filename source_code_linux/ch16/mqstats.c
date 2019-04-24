
#include <stdio.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
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

    if (ret == 0) {

      printf( "Number of messages queued: %ld\n", 
               buf.msg_qnum );
      printf( "Number of bytes on queue : %ld\n", 
               buf.msg_cbytes );
      printf( "Limit of bytes on queue  : %ld\n", 
               buf.msg_qbytes );

      printf( "Last message writer (pid): %d\n", 
               buf.msg_lspid );
      printf( "Last message reader (pid): %d\n", 
               buf.msg_lrpid );

      printf( "Last change time         : %s", 
               ctime(&buf.msg_ctime) );

      if (buf.msg_stime) {
        printf( "Last msgsnd time         : %s", 
                 ctime(&buf.msg_stime) );
      }
      if (buf.msg_rtime) {
        printf( "Last msgrcv time         : %s", 
                 ctime(&buf.msg_rtime) );
      }

    }

  }

  return 0;
}

