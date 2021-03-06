#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

double dwalltime();
void imprimeVector(uint64_t *V, uint64_t size);

int main(int argc,char*argv[]){
  //Controla los argumentos al programa
  if (argc < 5){
    printf("\n Falta un argumento : \n");
    printf("\t * N cantidad de elementos del vector\n");
    printf("\t * MAX_NUM numero maximo de cada elemento del vector\n");
    printf("\t * X elemento a buscar ocurrencias \n");
    printf("\t * T cantidad de threads \n");
    printf("\t * I imprime?\n");
    return 1;
  }

  uint64_t ocurrencias = 0;
  int I;
  double timetick;
  uint64_t N, M, X, T, i;
  uint64_t *vector;

  N = atoi(argv[1]);
  M = atoi(argv[2]);
  X = atoi(argv[3]);
  T = atoi(argv[4]);
  I = atoi(argv[5]);
  omp_set_num_threads(T);

  if (N < T) {
    printf("Cantidad de elementos no puede ser menor a la cantidad de threads");
    return 1;
  }

  // Genero el vector de N elementos con numero aleatorios
  srand(time(NULL));
  vector = (uint64_t*)malloc(sizeof(uint64_t)*N);
  for (i=0; i<N; i++) {
    vector[i] = (rand() % M) + 1;
  }

  printf("\t * %llu : cantidad de elementos del vector\n", N);
  printf("\t * %llu : numero maximo de cada elemento del vector\n", M);
  printf("\t * %llu : elemento a buscar ocurrencias \n", X);
  printf("\t * %llu : cantidad de threads \n", T);
  if ( I == 1 )
    imprimeVector(vector, N);

  timetick = dwalltime();
  #pragma omp parallel for reduction(+ : ocurrencias)
    for (i=0; i<N; i++) {
      if (vector[i] == X)
        ocurrencias++;
    }

  printf("Tiempo en segundos %f \n", dwalltime() - timetick);
  printf("\n\t Se encontraron %llu ocurrencias\n", ocurrencias);

  return 0;
}

/*****************************************************************/

#include <sys/time.h>

double dwalltime()
{
  double sec;
  struct timeval tv;

  gettimeofday(&tv,NULL);
  sec = tv.tv_sec + tv.tv_usec/1000000.0;
  return sec;
}

void imprimeVector(uint64_t *V, uint64_t size){
  printf("Imprimiendo matriz...\n");
  uint64_t i;
  printf("[");
  for (i=0; i<size; i++) {
    if (i==size-1)
      printf("%llu]\n", V[i]);
    else
      printf("%llu, ", V[i]);
  }
}
