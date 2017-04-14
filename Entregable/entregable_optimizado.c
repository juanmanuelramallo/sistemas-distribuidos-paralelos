#include <stdio.h>
#include <stdlib.h>

/* Time in seconds from some point in the past */
double dwalltime();

int main(int argc,char*argv[]){
  int N = atoi(argv[1]);
  double *A,*B,*C ,*D,*db,*bc, *abc, *tot;
  double sumaD,sumaB;
  double promD,promB;
  double total = (double) 1/(N*N);
  int i,j,k;
  int check=1;
  double timetick;

 //Controla los argumentos al programa
  if (argc < 2){
   printf("\n Falta un argumento:: N dimension de la matriz \n");
   return 0;
  }

  //Aloca memoria para las matrices
  A=(double*)malloc(sizeof(double)*N*N);
  B=(double*)malloc(sizeof(double)*N*N);
  C=(double*)malloc(sizeof(double)*N*N);
  D=(double*)malloc(sizeof(double)*N*N);
  db=(double*)malloc(sizeof(double)*N*N);
  bc=(double*)malloc(sizeof(double)*N*N);
  abc=(double*)malloc(sizeof(double)*N*N);
  tot=(double*)malloc(sizeof(double)*N*N);


  //Inicializa las matrices A y B en 1, el resultado sera una matriz con todos sus valores en N
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      A[i*N+j]=1;   // Por filas
      B[i+j*N]=1;   // Por columnas
      C[i+j*N]=1;   // Por columnas
      D[i*N+j]=1;   // Por filas
    }
  }

  timetick = dwalltime();

  // Calcula D*B y la suma de los elementos de cada una
  sumaB = sumaD = 0;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      db[i*N+j]=0;
      sumaD += D[i*N+j];
      sumaB += B[i+j*N];
      for(k=0;k<N;k++){
        db[i*N+j]= db[i*N+j] + D[i*N+k]*B[k+j*N];
      }
    }
  }

  // Calcula el promedio de los elementos de las metrices D y B
  promB = sumaB*total;
  promD = sumaD*total;

  // Suma promD*B + promB*C
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      bc[i+j*N]= promD*B[i+j*N] + promB*C[i+j*N];
    }
  }

  // Multiplica A con promD*B + promB*C
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      abc[i*N+j]=0;
      for(k=0;k<N;k++){
        abc[i*N+j]= abc[i*N+j] + A[i*N+k]*bc[k+j*N];
      }
    }
  }

  // Suma los dos terminos
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      tot[i*N+j]= abc[i*N+j]+db[i*N+j];
    }
  }

  printf("Tiempo en segundos %f \n", dwalltime() - timetick);

  //Verifica el resultado
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      check=check&&(tot[i*N+j]==N*3);
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
 free(D);
 free(abc);
 free(bc);
 free(db);
 free(tot);

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
