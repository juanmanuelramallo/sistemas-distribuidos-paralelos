#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

double dwalltime();
void imprimeVector(uint64_t *V, uint64_t size);
void* buscaExtremos(void* index);

uint64_t *vector;
uint64_t N, M, T, i;

typedef struct extremos {
  uint64_t max;
  uint64_t min;
} Extremos;

Extremos *extremosPorHilo;

int main(int argc,char*argv[]){
  //Controla los argumentos al programa
  if (argc < 4){
    printf("\n Falta un argumento : \n");
    printf("\t * N cantidad de elementos del vector\n");
    printf("\t * MAX_NUM numero maximo de cada elemento del vector\n");
    printf("\t * T cantidad de threads \n");
    printf("\t * I imprime?\n");
    return 1;
  }

  int I;
  double timetick;
  uint64_t max = 0;
  uint64_t min = UINT64_MAX;

  N = atoi(argv[1]);
  M = atoi(argv[2]);
  T = atoi(argv[3]);
  I = atoi(argv[4]);

  if (N < T) {
    printf("Cantidad de elementos no puede ser menor a la cantidad de threads");
    return 1;
  }

  extremosPorHilo = (Extremos*)malloc(sizeof(Extremos)*T);
  for (i=0; i<T; i++) {
    extremosPorHilo[i].max = 0;
    extremosPorHilo[i].min = UINT64_MAX;
  }

  uint64_t threadIds[T];
  // Genero el vector de N elementos con numero aleatorios
  srand(time(NULL));
  vector = (uint64_t*)malloc(sizeof(uint64_t)*N);
  for (i=0; i<N; i++) {
    vector[i] = (rand() % M) + 1;
  }

  printf("\t * %llu : cantidad de elementos del vector\n", N);
  printf("\t * %llu : numero maximo de cada elemento del vector\n", M);
  printf("\t * %llu : cantidad de threads \n", T);
  if ( I == 1 )
    imprimeVector(vector, N);

  pthread_t threads[T];
  timetick = dwalltime();

  // El main tb es un hilo (se puede crear T-1 threads y usar el main tb como un hilo)
  for (i=1; i<T; i++) {
    threadIds[i] = i;
    pthread_create(&threads[i], NULL, buscaExtremos, (void*)&threadIds[i]);
  }

  // El hilo main no es un holgazán
  i = 0;
  buscaExtremos((void*) i);

  for (i=1; i<T; i++) {
    pthread_join(threads[i], NULL);
  }

  for (i=0; i<T; i++) {
    if (extremosPorHilo[i].max > max)
      max = extremosPorHilo[i].max;
    if (extremosPorHilo[i].min < min)
      min = extremosPorHilo[i].min;
  }

  printf("Tiempo en segundos %f \n", dwalltime() - timetick);
  printf("\n\t El máximo es: %llu\n\t El mínimo es: %llu\n\n", max, min);

  free(extremosPorHilo);
  free(vector);

  return 0;
}

/*****************************************************************/

#include <sys/time.h>

void* buscaExtremos(void* ind) {
  uint64_t index = *((uint64_t *) ind);
  uint32_t i;
  uint32_t aux = index*(N/T) + ((N/T)-1);
  for (i=index*(N/T); i<aux; i++) {
    if (vector[i] > extremosPorHilo[index].max)
      extremosPorHilo[index].max = vector[i];
    if (vector[i] < extremosPorHilo[index].min)
      extremosPorHilo[index].min = vector[i];
  }
  pthread_exit(NULL);
}

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
