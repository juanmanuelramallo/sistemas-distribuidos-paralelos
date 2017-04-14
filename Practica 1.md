# PRACTICA 1

### Entornos
* Ubuntu
  * OS: Ubuntu 16.04 LTS
  * Memoria: 7.3 GiB
  *  Procesador: Intel Core i5-2310 CPU @ 2.90 GHz x 4
  *  Tipo de SO: 64 bits
* Sierra
  * OS: Mac OS Sierra
  * Memoria: 8 GB
  * Procesador: 2.9 GHz Intel Core i7
  * Tipo de SO: 64 bits

## EJERCICIO 1
* Entorno: Ubuntu


  |Matrices    |   Normal  |  Mejorado |
  |-----------:|----------:|----------:|
  | 32x32      | 0.001075 |            |
  | 64x64      | 0.008528 |           |
  | 128x128    | 0.054091 |           |
  | 256x256    | 0.335244 |           |
  | 512x512    | 2.496279 |           |
  | 1024x1024  |          |           |
  | 2048 x 2048|          |           |

* Entorno: Sierra


  |Matrices:   |    Normal  |   Mejorada
  |-----------:|-----------:|------------:|
  |32x32       | 0.000757   | 0.000149|
  | 64x64      | 0.006124   |0.001134|
  | 128x128    | 0.057123   |0.012789|
  | 256x256    | 0.351736   |0.120285|
  | 512x512    | 3.060068   |1.781699|
  | 1024x1024  | 53.343500  |30.655217|
  | 2048x2058  | 494.388668 | 275.633829|

  Se logró una mejora considerable (55% más rápido aprox.) en el tiempo de ejecución al eliminar todas las llamadas a funciones en la función principal y disponer de tales operaciones directamente en el mismo bloque de código del main.

## Ejercicio 2

* Entorno: Sierra


  | Tamaño       |Base       |Opt       |
  | -------------|:---------:|---------:|
  | 32x32        | 0.000376  | 0.000345 |
  | 64x64        | 0.006192  | 0.002737 |
  | 128x128      | 0.031272  | 0.019873 |
  | 256x256      | 0.196097  | 0.151346 |
  | 512x512      | 1.594603  | 1.223936 |
  | 1024x1024    | 12.831295 | 9.937923 |
  | 2048x2058    | 103.170263| 79.075616|



 [ 1 ] [ 2 ] [ 3 ]      [ 10 ] [ 11 ] [ 12 ]
 [ 4 ] [ 5 ] [ 6 ]      [ 13 ] [ 14 ] [ 15 ]
 [ 7 ] [ 8 ] [ 9 ]      [ 16 ] [ 17 ] [ 18 ]
