#!/bin/bash
outer=0

while [ "$outer" -lt 5 ] ; do

  inner=0

  while [ "$inner" -lt 3 ] ; do

    echo "$outer * $inner = $(($outer * $inner))"

    inner=$(expr $inner + 1)

  done

  let outer=$outer+1

done

exit

