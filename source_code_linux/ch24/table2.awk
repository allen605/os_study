BEGIN {
  i = 1
  while (i <= 10) {
    printf( "%2d %f %f %f\n", i, sqrt(i), log(i), rand() )
    i++
  }
}
