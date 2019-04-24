/*
 * Random Init Function API File
 *
 */

#include <stdlib.h>
#include <time.h>


/*
 *  initRand() initializes the random number generator.
 *
 */

void initRand()
{
  time_t seed;

  seed = time(NULL);

  srand( seed );

  return;
}

