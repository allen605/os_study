#!/bin/bash

char=f

case "$char" in
  [a-zA-z] ) echo "An upper or lower case character" ;;
  [0-9]    ) echo "A number" ;;
  *        ) echo "Something else" ;;
esac

exit

