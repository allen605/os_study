#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF         128

int main()
{
  int fd;
  char buf[MAX_BUF+1];

  fd = open( "myfile.txt", O_RDONLY );

  read( fd, buf, MAX_BUF );

  printf( "read %s\n", buf );

  close( fd );
}

