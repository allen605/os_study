#include <stdio.h>
#include <getopt.h>

static struct option longopts[] = {
  { "start",   no_argument,           0,  's' },
  { "stop",    no_argument,           0,  't' },
  { "command", required_argument,     0,  'c' },
  { NULL,      0,                  NULL,   0 }
};


int main( int argc, char *argv[] )
{
  int c;

  while ( (c = getopt_long( argc, argv, "stc:", longopts, NULL)) != -1 ) {

    switch( c ) {

      case 's':
        printf( "Start!\n" );
        break;

      case 't':
        printf( "Stop!\n" );
        break;

      case 'c':
        printf( "Command %s!\n", optarg );
        break;

      case '?':
      default:
        printf( "Unknown option\n");
        break;

    }

  }

  return 0;
}
