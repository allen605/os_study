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

  /* Get the last entry */
  fseek( fin, (2 * sizeof(MY_TYPE_T)), SEEK_SET );

  fread( &object, sizeof(MY_TYPE_T), 1, fin );

  printf("%d %f %f %s\n", 
           object.id, 
           object.x_coord, object.y_coord,
           object.name );

  /* Get the second to last entry */
  rewind( fin );

  fseek( fin, (1 * sizeof(MY_TYPE_T)), SEEK_SET );

  fread( &object, sizeof(MY_TYPE_T), 1, fin );

  printf("%d %f %f %s\n", 
           object.id, 
           object.x_coord, object.y_coord,
           object.name );

  /* Get the first entry */
  rewind( fin );

  fread( &object, sizeof(MY_TYPE_T), 1, fin );

  printf("%d %f %f %s\n", 
           object.id, 
           object.x_coord, object.y_coord,
           object.name );

  fclose( fin );

  return 0;
}

