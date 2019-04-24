
#define STACK_CREATED	0xFAF32000

typedef struct {

  int state;
  int index;
  int max;
  int *storage;

} stack_t;


int stackCreate( stack_t *stack, int stackSize );

int stackCreate( stack_t *stack, int element );

int stackPop( stack_t *stack, int *element );

int stackDestroy( stack_t *stack );


