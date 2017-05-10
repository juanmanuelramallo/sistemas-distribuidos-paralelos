#/!bin/bash

gcc -pthread -o uno_pthread.o uno_pthread.c

echo " ================= 1 con pthread =================== "
for size in 512 1024 2048
do
  echo " ==================================================== Matriz $((size)) "
  for thread in 2 4
  do
    echo " ---------------------------> Threads -> $thread"
    ./uno_pthread.o $size $thread
  done
done
