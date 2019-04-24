#!/bin/bash
for i in `seq 1 5`; do
  ./sort
  mv gmon.out gmon.out.$i
done

gprof -s sort gmon.out.*
gprof -b --no-graph sort gmon.sum

