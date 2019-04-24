#include <sys/sysinfo.h>
#include <stdio.h>

int main()
{
  struct sysinfo info;
  int ret;
  int days, hours, minutes, seconds;

  ret = sysinfo( &info );

  if (ret == 0) {

    printf( "Uptime is %ld\n", info.uptime );

    days = info.uptime / (24 * 60 * 60);
    info.uptime -= (days * (24 * 60 * 60));
    hours = info.uptime / (60 * 60);
    info.uptime -= (hours * (60 * 60));
    minutes = info.uptime / 60;
    info.uptime -= (minutes * 60);
    seconds = info.uptime;

    printf( "%d Days %d Hours %d Minutes %d Seconds\n", 
            days, hours, minutes, seconds );
    printf( "One minute load average %ld\n", info.loads[0] );
    printf( "Five minute load average %ld\n", info.loads[1] );
    printf( "Fifteen minute load average %ld\n", info.loads[2] );
    printf( "Total Ram Available %ld\n", info.totalram );
    printf( "Free Ram Available %ld\n", info.freeram );
    printf( "Shared Ram Available %ld\n", info.sharedram );
    printf( "Buffer Ram Available %ld\n", info.bufferram );
    printf( "Total Swap Size %ld\n", info.totalswap );
    printf( "Available Swap Size %ld\n", info.freeswap );
    printf( "Processes running: %d\n", info.procs );
    printf( "Total high memory size %ld\n", info.totalhigh );
    printf( "Available high memory %ld\n", info.freehigh );
    printf( "Memory Unit size %d\n", info.mem_unit );
  }

  return 0;
}

