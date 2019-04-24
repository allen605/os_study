#!/bin/bash

name="Tim"

case "$name" in
  "Dan"          ) echo "It's Dan." ;;
  "Marc" | "Tim" ) echo "It's me." ;;
  "Ronald"       ) echo "It's Ronald." ;;
  *              ) echo "I don't know you." ;;
esac

exit

