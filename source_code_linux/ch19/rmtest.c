#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char filename[L_tmpnam+1] = "fileXXXXXX";
  int err;

  err = mkstemp( filename );

  fp = fopen( filename, "w" );
  if (fp != NULL) {

    fclose(fp);

    err = remove( filename );

    if (!err) printf("%s removed\n", filename);

  }

  return 0;
}
