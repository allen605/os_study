#!/bin/bash
var=2

case "$var" in
  0) echo "The value is 0" ;;
  1) echo "The value is 1" ;;
  2) echo "The value is 2" ;;
  *) echo "The value is not 0, 1, or 2"
esac

exit

