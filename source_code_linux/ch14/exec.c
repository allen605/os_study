#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
  int ret;

  ret = execl( "/bin/ls", "ls", "-la", NULL );

  printf("Never get here...\n");

  return 0;
}
