#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main( int argc, char *argv[] )
{
  DIR *dirp;
  struct stat statbuf;
  struct dirent *dp;

  if (argc < 2) return 1;

  if (stat(argv[1], &statbuf) == -1) return 1;

  if (!S_ISDIR(statbuf.st_mode)) return 1;

  dirp = opendir( argv[1] );

  while ((dp = readdir(dirp)) != NULL) {

    if (stat(dp->d_name, &statbuf) == -1) continue;
    if (!S_ISREG(statbuf.st_mode)) continue;

    printf("%s\n", dp->d_name);

  }

  closedir(dirp);

  return 0;
}
