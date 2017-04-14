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

Comentarios: Para correr un ejercicio `chmod 777 ejercicioX.sh` y luego `./ejercicioX`

## [EJERCICIO 1](ejercicio1.sh)
#### Entorno: Ubuntu


  |Matrices    |   Normal  |  Mejorado |
  |-----------:|----------:|----------:|
  | 32x32      | 0.001075 |            |
  | 64x64      | 0.008528 |           |
  | 128x128    | 0.054091 |           |
  | 256x256    | 0.335244 |           |
  | 512x512    | 2.496279 |           |
  | 1024x1024  |          |           |
  | 2048 x 2048|          |           |

#### Entorno: Sierra


  |Matrices:   |    [Normal](matrices.c)  |   [Mejorada](matrices-mejorado.c)
  |-----------:|-----------:|------------:|
  |32x32       | 0.000757   | 0.000149|
  | 64x64      | 0.006124   |0.001134|
  | 128x128    | 0.057123   |0.012789|
  | 256x256    | 0.351736   |0.120285|
  | 512x512    | 3.060068   |1.781699|
  | 1024x1024  | 53.343500  |30.655217|
  | 2048x2058  | 494.388668 | 275.633829|

  Se logró una mejora considerable (55% más rápido aprox.) en el tiempo de ejecución al eliminar todas las llamadas a funciones en la función principal y disponer de tales operaciones directamente en el mismo bloque de código del main.

## [Ejercicio 2](ejercicio2.sh)

* Entorno: Sierra


  | Tamaño       |[Base](SumMulMatrices.c)       |[Opt](SumMulMatricesOpt.c)       |
  | -------------|:---------:|---------:|
  | 32x32        | 0.000376  | 0.000345 |
  | 64x64        | 0.006192  | 0.002737 |
  | 128x128      | 0.031272  | 0.019873 |
  | 256x256      | 0.196097  | 0.151346 |
  | 512x512      | 1.594603  | 1.223936 |
  | 1024x1024    | 12.831295 | 9.937923 |
  | 2048x2058    | 103.170263| 79.075616|


## [Ejercicio 3](ejercicio3.sh)

#### Entorno: Sierra

  Tamaño matriz:
  * 32 x 32:


  | Cant. bloques | Tamaño Bloques| Tiempo |
  |-:|-:|-:|
  | 1 | 32 | 0.000129 |
  | 2 | 16 | 0.000125 |
  | 4 | 8 | 0.000214 |
  | 8 | 4 | 0.000294 |
  | 16 | 2 | 0.000178 |

  * 64 x 64


  | Cant. bloques | Tamaño Bloques| Tiempo |
  |-:|-:|-:|
  | 1 | 64 | 0.001886 |
  | 2 | 32 | 0.001080 |
  | 4 | 16 | 0.001229 |
  | 8 | 8 | 0.001969 |
  | 16 | 4 | 0.001443 |
  | 32 | 2 | 0.001424 |

  * 128 x 128


  | Cant. bloques | Tamaño Bloques| Tiempo |
  |-:|-:|-:|
  | 1 | 128 | 0.009054 |
  | 2 | 64 | 0.010496 |
  | 4 | 32 | 0.008472 |
  | 8 | 16 | 0.010434 |
  | 16 | 8 | 0.009961 |
  | 32 | 4 | 0.009966 |
  | 64 | 2 | 0.011384 |

  * 256 x 256


  | Cant. bloques | Tamaño Bloques| Tiempo |
  |-:|-:|-:|
  | 1 | 256 | 0.103297 |
  | 2 | 128 | 0.074333 |
  | 4 | 64 | 0.082778 |
  | 8 | 32 | 0.067971 |
  | 16 | 16 | 0.069003 |
  | 32 | 8 | 0.074318 |
  | 64 | 4 | 0.080487 |
  | 128 | 2 | 0.123770 |

  * 512 x 512


  | Cant. bloques | Tamaño Bloques| Tiempo |
  |-:|-:|-:|
  | 1 | 512 | 0.939195 |
  | 2 | 256 | 0.803877 |
  | 4 | 128 | 0.660884 |
  | 8 | 64 | 0.612996 |
  | 16 | 32 | 0.576694 |
  | 32 | 16 | 0.565228 |
  | 64 | 8 | 0.643460 |
  | 128 | 4 | 0.656603 |
  | 256 | 2 | 1.161320 |
  | 512 | 1 | 2.169332 |

  * 1024 x 1024


  | Cant. bloques | Tamaño Bloques| Tiempo |
  |-:|-:|-:|
  | 1 | 1024 | 25.637675 |
  | 2 | 512 | 8.006854 |
  | 4 | 256 | 6.652124 |
  | 8 | 128 | 4.798431 |
  | 16 | 64 | 4.541295 |
  | 32 | 32 | 4.366629 |
  | 64 | 16 | 4.334878 |
  | 128 | 8 | 4.922300 |
  | 256 | 4 | 5.954140 |
  | 512 | 2 | 9.234574 |
  | 1024 | 1 | 50.378868 |

  * 2048 x 2048


  | Cant. bloques | Tamaño Bloques| Tiempo |
  |-:|-:|-:|
  | 1 | 2048 | 217.507716 |
  | 2 | 1024 | 200.420534 |
  | 4 | 512 | 55.890847 |
  | 8 | 256 | 50.832388 |
  | 16 | 128 | 37.066588 |
  | 32 | 64 | 34.907470 |
  | 64 | 32 | 34.353228 |
  | 128 | 16 | 33.696721 |
  | 256 | 8 | 37.459602 |
  | 512 | 4 | 47.920537 |
  | 1024 | 2 | 125.588542 |


  ## [Entregable](Entregable por bloques.md)
