#!/bin/bash

echo " - Practica 1 - Ejercicio 1"

gcc -o matrices.o matrices.c
gcc -o matrices-mejorado.o matrices-mejorado.c
mv *.o outputs
rm -f *.o

cd outputs

for var in 32 64 128 256 512 1024 2048
do
  echo " ---------------------------------------------------- Matriz $var x $var --"
  echo " --- NORMAL -> "
  ./matrices.o $var
  echo " --- MEJORADO ->"
  ./matrices-mejorado.o $var
done
