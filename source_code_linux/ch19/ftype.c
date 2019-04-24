#include <stdio.h>
#include <sys/stat.h>

int main( int argc, char *argv[] )
{
  struct stat statbuf;

  /* Check to see if a filename was provided */
  if (argc < 2) {
    printf("specify a file to test\n");
    return 1;
  }

  /* Obtain stat information on the file */
  if ( stat(argv[1], &statbuf) == -1 ) {
    printf("Can't stat file\n");
    return 1;
  }

  printf("%s ", argv[1]);

  /* Determine the file type from the st_mode */
  if        (S_ISDIR(statbuf.st_mode)) {
    printf("is a directory\n");
  } else if (S_ISCHR(statbuf.st_mode)) {
    printf("is a character special file\n");
  } else if (S_ISBLK(statbuf.st_mode)) {
    printf("is a block special file\n");
  } else if (S_ISREG(statbuf.st_mode)) {
    printf("is a regular file\n");
  } else if (S_ISFIFO(statbuf.st_mode)) {
    printf("is a FIFO special file\n");
  } else if (S_ISLNK(statbuf.st_mode)) {
    printf("is a symbolic link\n");
  } else if (S_ISSOCK(statbuf.st_mode)) {
    printf("is a socket\n");
  } else {
    printf("is unknown\n");
  }

  return 0;
}
