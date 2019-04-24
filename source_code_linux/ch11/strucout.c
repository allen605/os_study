#include <stdio.h>

#define MAX_LINE	40

#define FILENAME "myfile.txt"

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

  /* Open the output file */
  fout = fopen( FILENAME, "w" );
  if (fout == (FILE *)0) exit(-1);

  /* Emit each of the objects, one per line */
  for ( i = 0 ; i < MAX_OBJECTS ; i++ ) {

    fprintf( fout, "%d %f %f %s\n",
             objects[i].id, 
             objects[i].x_coord, objects[i].y_coord,
             objects[i].name );

  }

  fclose( fout );

  return 0;
}

