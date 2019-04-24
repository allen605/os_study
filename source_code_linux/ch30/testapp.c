#include <stdio.h>
#include <assert.h>

#define MAX_STACK_ELEMS		10

#define OP_ADD			0
#define OP_SUBTRACT		1
#define OP_MULTIPLY		2
#define OP_DIVIDE		3


typedef struct {
  int stack[MAX_STACK_ELEMS];
  int index;
} STACK_T;


void initStack( STACK_T *stack )
{
  assert( stack );
  stack->index = 0;
}


void push( STACK_T *stack, int elem )
{
  assert( stack );
  assert( stack->index < MAX_STACK_ELEMS );

  stack->stack[stack->index++] = elem;
  return;
}


int pop( STACK_T *stack )
{
  assert( stack );
  assert( stack->index > 0 );

  return( stack->stack[--stack->index] );
}


void operator( STACK_T *stack, int op )
{
  int a, b;

  assert( stack );
  assert( stack->index > 0 );

  a = pop(stack); b = pop(stack);

  switch( op ) {

    case OP_ADD:
      push( stack, (a+b) ); break;

    case OP_SUBTRACT:
      push( stack, (a-b) ); break;

    case OP_MULTIPLY:
      push( stack, (a*b) ); break;

    case OP_DIVIDE:
      push( stack, (a/b) ); break;

    default:
      assert(0); break;

  }

}


int main()
{
  STACK_T stack;

  initStack(&stack);

  push( &stack, 2 );
  push( &stack, 5 );
  push( &stack, 2 );
  push( &stack, 3 );
  push( &stack, 5 );
  push( &stack, 3 );
  push( &stack, 6 );

  operator( &stack, OP_ADD );
  operator( &stack, OP_SUBTRACT );
  operator( &stack, OP_MULTIPLY );
  operator( &stack, OP_DIVIDE );
  operator( &stack, OP_ADD );
  operator( &stack, OP_SUBTRACT );
  
  printf( "Result is %d\n", pop( &stack ) ); 


  return 0;
}


