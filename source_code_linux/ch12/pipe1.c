#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE	80
#define PIPE_STDIN	0
#define PIPE_STDOUT	1

int main()
{
  const char *string={"A sample message."};
  int ret, myPipe[2];
  char buffer[MAX_LINE+1];

  /* Create the pipe */
  ret = pipe( myPipe );

  if (ret == 0) {

    /* Write the message into the pipe */
    write( myPipe[PIPE_STDOUT], string, strlen(string) );
    
    /* Read the message from the pipe */
    ret = read( myPipe[PIPE_STDIN], buffer, MAX_LINE );

    /* Null terminate the string */
    buffer[ strlen(buffer)-1 ] = 0;

    printf("%s\n", buffer);

  }

  return 0;
}

