#!/bin/bash

echo " - Practica 1 - Ejercicio 2"

gcc -o SumMulMatrices.o SumMulMatrices.c
gcc -o SumMulMatricesOpt.o SumMulMatricesOpt.c
mv *.o outputs
rm -f *.o

cd outputs

for var in 32 64 128 256 512 1024 2048
do
  echo " ---------------------------------------------------- Matriz $var x $var --"
  echo " --- BASE -> "
  ./SumMulMatrices.o $var
  echo " --- OPT -> "
  ./SumMulMatricesOpt.o $var
done
