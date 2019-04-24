#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  char *pathname;
  long  maxbufsize;

  maxbufsize = pathconf( ".", _PC_PATH_MAX );
  if (maxbufsize == -1) return 1;

  pathname = (char *)malloc(maxbufsize);

  (void)getcwd( pathname, (size_t)maxbufsize );

  printf("%s\n", pathname);

  free(pathname);

  return 0;
}
