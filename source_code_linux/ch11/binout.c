#include <stdio.h>

#define MAX_LINE	40

#define FILENAME "myfile.bin"

typedef struct {
  int id;
  float x_coord;
  float y_coord;
  char name[MAX_LINE+1];
} MY_TYPE_T;

#define MAX_OBJECTS	3

MY_TYPE_T objects[MAX_OBJECTS]={
  { 0, 1.5, 8.4, "First-object" },
  { 1, 9.2, 7.4, "Second-object" },
  { 2, 4.1, 5.6, "Final-object" }
};

int main()
{
  int i;
  FILE *fout;

  printf("sizeof %d\n", sizeof(float) );

  /* Open the output file */
  fout = fopen( FILENAME, "w" );
  if (fout == (FILE *)0) exit(-1);

  /* Write out the entire objects structure */
  fwrite( (void *)objects, sizeof(MY_TYPE_T), 3, fout );

  fclose( fout );

  return 0;
}

