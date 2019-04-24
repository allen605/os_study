#include <stdio.h>
#include <glob.h>

int main()
{
  glob_t globbuf;
  int    err, i;

  err = glob( "*.[ch]", 0, NULL, &globbuf );

  if (err == 0) {

    for (i = 0 ; i < globbuf.gl_pathc ; i++) {

      printf("%s\n", globbuf.gl_pathv[i]);

    }

    globfree( &globbuf );

  }

  return 0;
}

