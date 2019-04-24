#include <stdio.h>
#include "stack.h"
#include "cut.h"

stack_t myStack_1;
stack_t myStack_2;

void __CUT_BRINGUP__Explode( void )
{
  int ret;

  printf("Stack test bringup called\n");

  ret = stackCreate( &myStack_1, 5 );
  ASSERT( (ret == 0), "Stack 1 Creation." );

  ret = stackCreate( &myStack_2, 5 );
  ASSERT( (ret == 0), "Stack 2 Creation." );

}


void __CUT__PushConsumptionTest( void )
{
  int ret;

  /* Exhaust the stack */

  ret = stackPush( &myStack_1, 1 );
  ASSERT( (ret == 0), "Stack Push 1 failed." );

  ret = stackPush( &myStack_1, 2 );
  ASSERT( (ret == 0), "Stack Push 2 failed." );

  ret = stackPush( &myStack_1, 3 );
  ASSERT( (ret == 0), "Stack Push 3 failed." );

  ret = stackPush( &myStack_1, 4 );
  ASSERT( (ret == 0), "Stack Push 4 failed." );

  ret = stackPush( &myStack_1, 5 );
  ASSERT( (ret == 0), "Stack Push 5 failed." );

  ret = stackPush( &myStack_1, 6 );
  ASSERT( (ret == -1), "Stack exhaustion failed." );

}


void __CUT__PushPopTest( void )
{
  int ret;
  int value;

  /* Test two pushes and then two pops */

  ret = stackPush( &myStack_2, 55 );
  ASSERT( (ret == 0), "Stack Push of 55 failed." );

  ret = stackPush( &myStack_2, 101 );
  ASSERT( (ret == 0), "Stack Push of 101 failed." );

  ret = stackPop( &myStack_2, &value );
  ASSERT( (ret == 0), "Stack Pop failed." );
  ASSERT( (value == 101), "Stack Popped Wrong Value." );

  ret = stackPop( &myStack_2, &value );
  ASSERT( (ret == 0), "Stack Pop failed." );
  ASSERT( (value == 55), "Stack Popped Wrong Value." );

}


void __CUT_TAKEDOWN__Explode( void )
{
  int ret;

  ret = stackDestroy( &myStack_1 );
  ASSERT( (ret == 0), "Stack 1 Destruction." );

  ret = stackDestroy( &myStack_2 );
  ASSERT( (ret == 0), "Stack 2 Destruction." );

  printf( "\n\nTest Complete\n");
}

