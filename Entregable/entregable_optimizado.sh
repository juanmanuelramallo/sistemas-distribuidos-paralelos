#!/bin/bash

gcc -o entregable_optimizado.o entregable_optimizado.c
if [ ! -d "outputs" ]; then
  mkdir outputs
fi
mv *.o outputs

cd outputs
echo " ================= Algoritmo Optimizado =================== "
for var in 512 1024
do
  echo " -------------------------- Optimizado -> $var "
  ./entregable_optimizado.o $var
done
