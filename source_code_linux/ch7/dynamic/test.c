/*
 * Dynamic rand function test.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "randapi.h"

#define ITERATIONS	1000000L


int main()
{
  long  i;
  long  isum;
  float fsum;
  void  *handle;
  char  *err;

  void (*initRand_d)(void);
  float (*getSRand_d)(void);
  int (*getRand_d)(int);

  /* Open a handle to the dynamic library */
  handle = dlopen( "/usr/local/lib/libmyrand.so", RTLD_LAZY );
  if (handle == (void *)0) {
    fputs( dlerror(), stderr );
    exit(-1);
  }

  /* Check access to the initRand() function */
  initRand_d = dlsym( handle, "initRand" );
  err = dlerror();
  if (err != NULL) {
    fputs( err, stderr );
    exit(-1);
  }

  /* Check access to the getSRand() function */
  getSRand_d = dlsym( handle, "getSRand" );
  err = dlerror();
  if (err != NULL) {
    fputs( err, stderr );
    exit(-1);
  }

  /* Check access to the getRand() function */
  getRand_d = dlsym( handle, "getRand" );
  err = dlerror();
  if (err != NULL) {
    fputs( err, stderr );
    exit(-1);
  }
  

  /* Initialize the random number API */
  (*initRand_d)();

  /* Find the average of getRand(10) returns (0..9) */
  isum = 0L;
  for (i = 0 ; i < ITERATIONS ; i++) {

    isum += (*getRand_d)(10);

  }

  printf( "getRand() Average %d\n", (int)(isum / ITERATIONS) );


  /* Find the average of getSRand() returns */
  fsum = 0.0;
  for (i = 0 ; i < ITERATIONS ; i++) {

    fsum += (*getSRand_d)();

  }

  printf( "getSRand() Average %f\n", (fsum / (float)ITERATIONS) );

  /* Close our handle to the dynamic library */
  dlclose( handle );

  return;
}
