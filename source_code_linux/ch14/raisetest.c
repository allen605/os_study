#include <signal.h>
#include <stdio.h>

int main()
{
  raise( SIGPROF );

  return;
}
