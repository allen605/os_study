#!/bin/bash

curwd=$PWD
echo "Current subdir is $curwd"

cd /home

echo -n "Users on the system are:"
for user in *; do
  echo -n " $user"
done
echo

cd $curwd

exit
