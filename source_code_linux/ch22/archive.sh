#!/bin/bash

# First, do some error checking
if [ $# -ne 1 ] ; then
  echo "Usage is ./archive.sh <directory-name>"
  exit -1
fi

if [ ! -e $1 ] ; then
  echo "Directory does not exist"
  exit -1
fi

if [ ! -d $1 ] ; then
  echo "Target must be a directory."
  exit -1
fi

# Remove the existing archive
archive=$1.tgz

if [ -f $archive ] ; then
  rm -f $archive
fi

# Archive the directory
tar cfz $archive $1

exit
