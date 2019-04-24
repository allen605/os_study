#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

static int stopChild = 0;

void sigHandler( int sig, siginfo_t *siginfo, void *ignore )
{
  printf("Got SIGUSR1 from %d\n", siginfo->si_pid);
  stopChild=1;

  return;
}

int main()
{
  pid_t ret;
  int   status;
  int   role = -1;

  ret = fork();

  if (ret > 0) {

    printf("Parent: This is the parent process (pid %d)\n", getpid());

    /* Let the child init */
    sleep(1);

    kill( ret, SIGUSR1 );

    ret = wait( &status );

    role = 0;

  } else if (ret == 0) {

    struct sigaction act;

    printf("Child: This is the child process (pid %d)\n", getpid());

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = sigHandler;
    sigaction( SIGUSR1, &act, 0 );

    printf("Child Waiting...\n");
    while (!stopChild);

    role = 1;

  } else {

    printf("Parent: Error trying to fork() (%d)\n", errno);

  }

  printf("%s: Exiting...\n", ((role == 0) ? "Parent" : "Child"));

  return 0;
}


