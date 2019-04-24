#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <langinfo.h>

int main( int argc, char *argv[] )
{
  struct stat    statbuf;
  struct passwd *pwd;
  struct group  *grp;
  struct tm     *tm;
  char           tmstr[257];

  /* Check to see if a filename was provided */
  if (argc < 2) {
    printf("specify a file to test\n");
    return 1;
  }

  /* Obtain stat information on the file */
  if ( stat(argv[1], &statbuf) == -1 ) {
    printf("Can't stat file\n");
    return 1;
  }

  printf("File Size : %-d\n", statbuf.st_size);

  pwd = getpwuid(statbuf.st_uid);
  if (pwd) printf("File Owner: %s\n", pwd->pw_name);

  grp = getgrgid(statbuf.st_gid);
  if (grp) printf("File Group: %s\n", grp->gr_name);

  tm = localtime(&statbuf.st_mtime);
  strftime( tmstr, sizeof(tmstr), nl_langinfo(D_T_FMT), tm);
  printf("File Date : %s\n", tmstr);

  return 0;
}
