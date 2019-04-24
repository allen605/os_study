
#include "randapi.h"

#define ITERATIONS	1000000L

int main()
{
  long  i;
  long  isum;
  float fsum;

  /* Initialize the random number API */
  initRand();

  /* Find the average of getRand(10) returns (0..9) */
  isum = 0L;
  for (i = 0 ; i < ITERATIONS ; i++) {

    isum += getRand(10);

  }

  printf( "getRand() Average %d\n", (int)(isum / ITERATIONS) );


  /* Find the average of getSRand() returns */
  fsum = 0.0;
  for (i = 0 ; i < ITERATIONS ; i++) {

    fsum += getSRand();

  }

  printf( "getSRand() Average %f\n", (fsum / (float)ITERATIONS) );

  return;
}
