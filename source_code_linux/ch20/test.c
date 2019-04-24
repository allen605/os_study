#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

int main( int argc, char *argv[] )
{
  int fd;
  unsigned char *addr, *waddr, count;
  int length;
  off_t offset;

  addr = (unsigned char *)mmap( 0xB0000000, 4096, 
                                 PROT_READ, MAP_SHARED|MAP_ANONYMOUS, -1, 0 );

printf("addr = %p (%x)\n", addr, *addr);

  munmap( addr, 4096 );

  return 0;
}
