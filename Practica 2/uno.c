#include <stdio.h>
#include <stdlib.h>

/* Time in seconds from some point in the past */
double dwalltime();
void imprimeMatriz(double *S,int N,int fil);

int main(int argc,char*argv[]){
  //Controla los argumentos al programa
  if (argc < 2){
    printf("\n Falta un argumento : \n");
    printf("\t * N dimension de la matriz \n");
    printf("\t * p cantidad de procesos \n");
    return 0;
  }

  int N = atoi(argv[1]);
  double *A,*B,*C;
  int i,j,k;
  int check=1;
  double timetick;

  //Aloca memoria para las matrices
  A=(double*)malloc(sizeof(double)*N*N);
  B=(double*)malloc(sizeof(double)*N*N);
  C=(double*)malloc(sizeof(double)*N*N);

  //Inicializa las matrices A y B en 1, el resultado sera una matriz con todos sus valores en N
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      A[i*N+j]=1;   // Por filas
      B[i+j*N]=1;   // Por columnas
    }
  }

  // imprimeMatriz(A, N, 1);
  // imprimeMatriz(B, N, 0);

  timetick = dwalltime();

  // Calcula D*B y la suma de los elementos de cada una
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      aux =0;
      for(k=0;k<N;k++){
        aux =  aux + A[i*N+k]*B[k+j*N];
      }
      C[i*N+j] = aux;
    }
  }

  // imprimeMatriz(C, N, 1);

  printf("Tiempo en segundos %f \n", dwalltime() - timetick);

  //Verifica el resultado
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      check=check&&(C[i*N+j]==N);
    }
  }

  if(check){
    printf("Multiplicacion de matrices resultado correcto\n");
  } else{
    printf("Multiplicacion de matrices resultado erroneo\n");
  }

 free(A);
 free(B);
 free(C);

 return(0);
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

void imprimeMatriz(double *S,int N,int fil){
  int i,j;
  printf("\nImprimiendo matriz\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if (fil == 1)
        printf("%.2lf\t", S[i*N+j]);
      else
        printf("%.2lf\t", S[i+j*N]);
    }
    printf("\n");
  }
  printf("\n");
}
