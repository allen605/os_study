#!/bin/sh
thefile="fileatt.sh"

if [ -e $thefile ]
then
  echo "File Exists"

  if [ -f $thefile ]
  then
    echo "regular file"
  elif [ -d $thefile ]
  then
    echo "directory"
  elif [ -h $thefile ]
  then
    echo "symbolic link"
  fi

else
  echo "File not present"
fi

exit

