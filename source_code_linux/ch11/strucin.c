#include <stdio.h>

#define MAX_LINE	40

#define FILENAME "myfile.txt"

typedef struct {
  int id;
  float x_coord;
  float y_coord;
  char name[MAX_LINE+1];
} MY_TYPE_T;

MY_TYPE_T object;

int main()
{
  int i;
  FILE *fin;

  /* Open the input file */
  fin = fopen( FILENAME, "r" );
  if (fin == (FILE *)0) exit(-1);

  /* Read the records from the file and emit */
  while ( !feof(fin) ) {

    fscanf( fin, "%d %f %f %s\n",
             &object.id, 
             &object.x_coord, &object.y_coord,
             object.name );

    printf("%d %f %f %s\n", 
             object.id, 
             object.x_coord, object.y_coord,
             object.name );

  }

  fclose( fin );

  return 0;
}

