#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main( int argc, char *argv[] )
{
  int c;

  while ( (c = getopt( argc, argv, "hv:f:d" ) ) != -1 ) {

    switch( c ) {

      case 'h':
        printf( "Help menu.\n" );
        break;

      case 'v':
        printf( "Verbose level = %d\n", atoi(optarg) );
        break;

      case 'f':
        printf( "Filename is = %s\n", optarg );
        break;

      case 'd':
        printf( "Debug mode\n" );
        break;

      case '?':
        printf( "Unrecognized option encountered -%c\n", optopt );

      default:
        exit(-1);

    }

  }

  for ( c = optind ; c < argc ; c++ ) {

    printf( "Non option %s\n", argv[c] );

  }

  /*
   *  Option parsing complete...
   */

  return 0;
}

