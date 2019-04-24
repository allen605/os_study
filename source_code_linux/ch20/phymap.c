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

  if (argc < 3) {

    printf( "Usage is phymap <address> <length>\n");
    exit(-1);

  }

  if (argv[1][1] == 'x') {
    sscanf( argv[1], "0x%x", &offset );
  } else {
    sscanf( argv[1], "%d", &offset );
  }

  if (argv[2][1] == 'x') {
    sscanf( argv[2], "0x%x", &length );
  } else {
    sscanf( argv[2], "%d", &length );
  }

  fd = open( "/dev/mem", O_RDONLY );

  if (fd != -1) {

    addr = (unsigned char *)mmap( NULL, length, 
                                   PROT_READ, MAP_SHARED, fd, offset );

    if (addr != NULL) {

      waddr = addr;

      for ( count = 0 ; count < length ; count++ ) {

        if ( (count % 16) == 0 ) {

          printf( "\n%8p : ", waddr );

        }

        printf( "%02x ", *waddr++ );

      }

      munmap( addr, length );

    } else {

      printf("Unable to map memory.\n");

    }

    close(fd);
    printf("\n");

  }

  return 0;
}
