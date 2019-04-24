/*
 * randapi.c
 *
 * Random Functions API File
 *
 */

#include <stdlib.h>


/*
 *  getSRand() returns a number between 0 and 1.
 *
 */

float getSRand()
{
  float randvalue;

  randvalue = ((float)rand() / (float)RAND_MAX);

  return randvalue;
}


/*
 *  getRand() returns a number between 0 and max-1.
 *
 */

int getRand( int max )
{
  int randvalue;

  randvalue = (int)((float)max * rand() / (RAND_MAX+1.0));

  return randvalue;
}

