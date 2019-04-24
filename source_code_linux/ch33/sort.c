#include <stdio.h>

#define MAX_ELEMENTS 10000

static void insertSort( int list[], int size )
{
  int i, j, temp;

  for ( i = 1 ; i <= size-1 ; i++ ) {

    temp = list[i];

    for ( j = i-1 ; j >= 0 && (list[j] > temp) ; j-- ) {
      list[j+1] = list[j];
    }

    list[j+1] = temp;

  }

}

static void bubbleSort( int list[], int size )
{
  int i, j, temp, swap = 1;

  while (swap) {

    swap = 0;

    for ( i = (size-1) ; i >= 0 ; i-- ) {

      for ( j = 1 ; j <= i ; j++ ) {

        if ( list[j-1] > list[j] ) {

          temp = list[j-1];
          list[j-1] = list[j];
          list[j] = temp;
          swap = 1;

        }

      }

    }

  }

}


static void init_list( int list[], int size )
{
  int i;

  for ( i = 0 ; i < size ; i++ ) {
    list[i] = (size-i);
  }

  return;
}


int main()
{
  int list[MAX_ELEMENTS];

  /* Invoke the bubble sort algorithm */
  init_list( list, MAX_ELEMENTS );
  bubbleSort( list, MAX_ELEMENTS );
  init_list( list, MAX_ELEMENTS );
  insertSort( list, MAX_ELEMENTS );

}

