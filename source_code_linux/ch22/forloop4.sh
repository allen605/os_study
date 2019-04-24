#!/bin/bash

# Save the current directory
curwd=$PWD

# Change the current directory to /home
cd /home

echo -n "Users on the system are:"

# Loop through each file (via the wildcard)
for user in *; do
  echo -n " $user"
done
echo

# Return to the previous directory
cd $curwd

exit

