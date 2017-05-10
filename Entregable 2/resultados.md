## Resultados

```
#=> ./uno_secuencial.sh

================= 1 secuencial ===================
==================================================== Matriz 512
-------------------------- Cantidad bloques -> 16 Tamano bloque -> 32
Tiempo en segundos 2.277861
Multiplicacion de matrices resultado correcto
-------------------------- Cantidad bloques -> 32 Tamano bloque -> 16
Tiempo en segundos 2.290522
Multiplicacion de matrices resultado correcto
-------------------------- Cantidad bloques -> 64 Tamano bloque -> 8
Tiempo en segundos 2.646761
Multiplicacion de matrices resultado correcto
==================================================== Matriz 1024
-------------------------- Cantidad bloques -> 16 Tamano bloque -> 64
Tiempo en segundos 19.439924
Multiplicacion de matrices resultado correcto
-------------------------- Cantidad bloques -> 32 Tamano bloque -> 32
Tiempo en segundos 26.399302
Multiplicacion de matrices resultado correcto
-------------------------- Cantidad bloques -> 64 Tamano bloque -> 16
Tiempo en segundos 29.483509
Multiplicacion de matrices resultado correcto
==================================================== Matriz 2048
-------------------------- Cantidad bloques -> 16 Tamano bloque -> 128
Tiempo en segundos 215.512653
Multiplicacion de matrices resultado correcto
-------------------------- Cantidad bloques -> 32 Tamano bloque -> 64
Tiempo en segundos 196.299407
Multiplicacion de matrices resultado correcto

#=> ./uno_pthread.sh

================= 1 con pthread ===================
==================================================== Matriz 512
 ---------------------------> Threads -> 2
	 * 512 : dimension matriz
	 * 2 : cantidad de threads
Tiempo en segundos 1.015653
Multiplicacion de matrices resultado correcto
 ---------------------------> Threads -> 4
	 * 512 : dimension matriz
	 * 4 : cantidad de threads
Tiempo en segundos 0.989360
Multiplicacion de matrices resultado correcto
 ==================================================== Matriz 1024
 ---------------------------> Threads -> 2
	 * 1024 : dimension matriz
	 * 2 : cantidad de threads
Tiempo en segundos 7.780955
Multiplicacion de matrices resultado correcto
 ---------------------------> Threads -> 4
	 * 1024 : dimension matriz
	 * 4 : cantidad de threads
Tiempo en segundos 7.890525
Multiplicacion de matrices resultado correcto
 ==================================================== Matriz 2048
 ---------------------------> Threads -> 2
	 * 2048 : dimension matriz
	 * 2 : cantidad de threads
Tiempo en segundos 103.819505
Multiplicacion de matrices resultado correcto


#=> ./uno_openmp.sh

================= 1 con openmp ===================
==================================================== Matriz 512
---------------------------> Threads -> 2
  * 512 : dimension matriz
  * 2 : cantidad de threads
Tiempo en segundos 1.616034
Multiplicacion de matrices resultado correcto
---------------------------> Threads -> 4
  * 512 : dimension matriz
  * 4 : cantidad de threads
Tiempo en segundos 1.574925
Multiplicacion de matrices resultado correcto
==================================================== Matriz 1024
---------------------------> Threads -> 2
  * 1024 : dimension matriz
  * 2 : cantidad de threads
Tiempo en segundos 12.893484
Multiplicacion de matrices resultado correcto
---------------------------> Threads -> 4
  * 1024 : dimension matriz
  * 4 : cantidad de threads
Tiempo en segundos 21.321331
Multiplicacion de matrices resultado correcto
==================================================== Matriz 2048
---------------------------> Threads -> 2
  * 2048 : dimension matriz
  * 2 : cantidad de threads
Tiempo en segundos 164.348229
Multiplicacion de matrices resultado correcto


```
