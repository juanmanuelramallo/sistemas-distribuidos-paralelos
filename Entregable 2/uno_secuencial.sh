#!/bin/bash

gcc -o uno_secuencial.o uno_secuencial.c

echo " ================= 1 secuencial =================== "
for matriz in 512 1024 2048
do
  echo " ==================================================== Matriz $((matriz)) "
  for cantBloques in 16 32 64
  do
    tamBloque=$((matriz/cantBloques))
    echo " -------------------------- Cantidad bloques -> $cantBloques Tamano bloque -> $tamBloque"
    ./uno_secuencial.o $cantBloques $tamBloque 0
    tamBloque=$((tamBloque/2))
  done
done
