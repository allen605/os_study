#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int failed = 0;


void checkResult( int testnum, int result )
{
  if (result == 0) {
    printf( "*** Failed test number %d\n", testnum );
    failed++;
  } else {
    printf( "Test number %2d passed.\n", testnum );
  }
}


void test1( void )
{
  stack_t myStack;
  int ret;

  failed = 0;

  ret = stackCreate( 0, 0 );
  checkResult( 0, (ret == -1) );

  ret = stackCreate( &myStack, 0 );
  checkResult( 1, (ret == -1) );

  ret = stackCreate( &myStack, 65536 );
  checkResult( 2, (ret == -1) );

  ret = stackCreate( &myStack, 1024 );
  checkResult( 3, (ret == 0) );

  checkResult( 4, (myStack.state == STACK_CREATED) );

  checkResult( 5, (myStack.index == 0) );

  checkResult( 6, (myStack.max == 1024) );

  checkResult( 7, (myStack.storage != (int *)0) );

  ret = stackDestroy( 0 );
  checkResult( 8, (ret == -1) );

  ret = stackDestroy( &myStack );
  checkResult( 9, (ret == 0) );

  checkResult( 10, (myStack.state != STACK_CREATED) );

  if (failed == 0) printf( "test1 passed.\n");
  else printf("test1 failed\n");
}


int main()
{

  failed = 0;
  test1();

  return 0;
}

