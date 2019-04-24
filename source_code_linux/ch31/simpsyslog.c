#include <syslog.h>

int main()
{

  syslog( LOG_ERR, "Unable to load configuration!" );

  return 0;
}

