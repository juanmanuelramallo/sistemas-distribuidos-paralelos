#!/bin/bash

gcc -o entregable_bloques.o entregable_bloques.c
if [ ! -d "outputs" ]; then
  mkdir outputs
fi
mv *.o outputs

cd outputs
echo " ================= Algoritmo con Bloques =================== "
for matriz in 512 1024
do
  echo " ==================================================== Matriz $((matriz)) "
  tamBloque=$matriz
  for (( cantBloques=1; cantBloques<=matriz; cantBloques=cantBloques*2 ))
  do
    echo " -------------------------- Cantidad bloques -> $cantBloques Tamano bloque -> $tamBloque"
    ./entregable_bloques.o $cantBloques $tamBloque 0
    tamBloque=$((tamBloque/2))
  done
done
