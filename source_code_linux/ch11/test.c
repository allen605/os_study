
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define MYFILE	"missing.txt"

main()
{

  FILE *fin;

  /* Try to open the file for read */
  fin = fopen( MYFILE, "r" );

  /* Check for failure to open */
  if (fin == (FILE *)0) {

    /* Emit an error message and exit */
    printf("%s: %s\n", MYFILE, strerror( errno ) );
    exit(-1);

  }

  /* All was well, close the file */
  fclose( fin );

}
