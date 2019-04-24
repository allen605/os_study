#!/bin/bash
#
# fut.sh
#
#  Find files created/updated today.
#
#  Usage is:
#
#    fut.sh <dir>
#

function recurse()
{
  # 'cd' down into the named directory
  cd $1

  # Iterate through all of the files
  for file in * ; do

    # If the file is a directory, recurse
    if [ -d "$file" ] ; then
      recurse $file
    fi

    if [ -f "$file" ] ; then

      longfile=`ls -l --time-style=long-iso $file`

      check=`echo "$longfile" | grep "$today"`

      if [ -n "$check" ] ; then

        echo "$PWD/$file"

      fi

    fi

  done

  if [ "$1" != "." ] ; then
    cd ..
  fi

}


function main()
{
  today=`date "+%Y-%m-%d"`

  checkdir=$1

  if [ -z "$checkdir" ] ; then
    checkdir="."
  fi

  recurse $checkdir
}

main $1

exit

