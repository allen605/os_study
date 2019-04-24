BEGIN {
  for (i = 1 ; i <= 10 ; i++ ) {
    printf( "%2d %f %f %f\n", i, sqrt(i), log(i), rand() )
  }
}
