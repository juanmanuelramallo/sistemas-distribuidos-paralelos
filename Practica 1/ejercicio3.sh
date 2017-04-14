#!/bin/bash

gcc -o multBloques.o multBloques.c
mv *.o outputs
rm *.o

cd outputs

for matriz in 32 64 128 256 512 1024 2048
do
  echo " ==================================================== Matriz $((matriz)) "
  tamBloque=$matriz
  for (( cantBloques=1; cantBloques<=matriz; cantBloques=cantBloques*2 ))
  do
    echo " ------ Cantidad bloques -> $cantBloques Tamano bloque -> $tamBloque"
    ./multBloques.o $cantBloques $tamBloque 0
    tamBloque=$((tamBloque/2))
  done
done
