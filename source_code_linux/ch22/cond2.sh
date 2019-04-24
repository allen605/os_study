#!/bin/bash
x=5
y=8
if [[ $x -lt $y ]]
then
  echo "$x < $y"
elif [[ $x -gt $y ]]
then
  echo "$x > $y"
elif [[ $x -eq $y ]]
then
  echo "$x == $y"
fi

