#!/bin/bash

var=1

while [ "$var" -le 5 ]
do
  echo "var is $var"
  let var=$var+1
done

exit

