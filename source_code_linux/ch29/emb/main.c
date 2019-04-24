#include <embUnit/embUnit.h>

TestRef StackTest_tests( void );

int main( int argc, const char *argv[] )
{
  TestRunner_start();
    TestRunner_runTest( StackTest_tests() );
  TestRunner_end();
  return 0;
}
