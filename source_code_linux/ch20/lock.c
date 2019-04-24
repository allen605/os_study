#include <stdio.h>
#include <sys/mman.h>

char data[4096];

int main()
{
  int  ret;

  ret = mlock( &data, 4096 );

  printf("mlock ret = %d\n", ret);

  ret = munlock( &data, 4096 );

  printf("munlock ret = %d\n", ret);

  return 0;
}
