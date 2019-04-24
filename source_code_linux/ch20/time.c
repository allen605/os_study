#include <time.h>
#include <stdio.h>

int main()
{
  time_t currentTime;
  struct tm *tm_time;

  currentTime = time( NULL );
  tm_time = localtime( &currentTime );

  printf( "from localtime %02d:%02d:%02d\n",
          tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec );

  printf( "from ctime %s\n", ctime( &currentTime ) );

  printf( "from asctime/localtime %s\n", asctime( tm_time ) );

  tm_time = gmtime( &currentTime );

  printf( "from gmtime %02d:%02d:%02d\n",
          tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec );

  printf( "from asctime/gmtime %s\n", asctime( tm_time ) );

  currentTime = mktime( tm_time );

  printf( "from ctime/mktime %s\n", ctime( &currentTime ) );

  return 0;
}
