#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE	80

int main()
{
  int status;
  pid_t childpid;
  char cmd[MAX_LINE+1];
  char *sret;

  while (1) {

    printf("mysh>");

    sret = fgets( cmd, sizeof(cmd), stdin );

    if (sret == NULL) exit(-1);

    cmd[ strlen(cmd)-1] = 0;

    if (!strncmp(cmd, "bye", 3)) exit(0);

    childpid = fork();

    if (childpid == 0) {

      execlp( cmd, cmd, 0 );

    } else if (childpid > 0) {

      waitpid( childpid, &status, 0 );

    }

    printf("\n");

  }

  return 0;
}
