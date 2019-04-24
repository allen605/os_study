#include <stdio.h>
#include <ftw.h>

int fncheck( const char *file, const struct stat *sb, int flag )
{
  if (flag == FTW_F) printf("File %s (%d)\n", file, (int)sb->st_size);
  else if (flag == FTW_D) printf("Directory %s\n", file);

  return 0;
}

int main( int argc, char *argv[] )
{
  if (argc < 2) return 1;

  ftw( argv[1], fncheck, 1 );

  return 0;
}
