#include <stdio.h>

int main()
{
  int i;
  FILE *fout;
  const char string[]={"This\r\nis a test\r\nfile.\r\n\0"};

  fout = fopen("inpfile.txt", "w");

  if (fout == (FILE *)0) exit(-1);

  i = 0;
  while (string[i] != 0) {

    fputc( (int)string[i], fout );
    i++;

  }

  fclose( fout );

  return 0;
}
