#!/bin/bash

gcc -fopenmp -o uno_openmp.o uno_openmp.c

echo " ================= 1 con openmp =================== "
for size in 512 1024 2048
do
  echo " ==================================================== Matriz $((size)) "
  for thread in 2 4
  do
    echo " ---------------------------> Threads -> $thread"
    ./uno_openmp.o $size $thread
  done
done
