#include <stdio.h>
#include <unistd.h>

int main( int argc, char *argv[], char *envp[] )
{
  int ret;
  char *args[]={ "ls", "-la", NULL };

  ret = execve( "/bin/ls", args, envp );

  fprintf( stderr, "execve failed.\n" );

  return 0;
}
