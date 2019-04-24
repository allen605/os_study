#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void wakeup( int sig_num )
{
  raise(SIGUSR1);
}

#define MAX_BUFFER	80

int main()
{
  char buffer[MAX_BUFFER+1];
  int ret;

  signal( SIGALRM, wakeup );

  printf("You have 3 seconds to enter the password\n");

  alarm(3);

  ret = read( 0, buffer, MAX_BUFFER );

  alarm(0);

  if (ret == -1) {

    printf("Times up...\n");

  } else {

    buffer[strlen(buffer)-1] = 0;
    printf("User entered %s\n", buffer);

  }

  return 0;
}

