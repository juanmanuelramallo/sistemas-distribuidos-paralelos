#include <stdio.h>
// #include <malloc.h>
#include <stdlib.h>
#include <math.h>

/* Time in seconds from some point in the past */
double dwalltime();

void producto(double *A,double *B,double *C, int r,int N,int sizeMatrix,int sizeBlock);
void producto_por_un_escalar(double valor, double *A, double *R, int r,int N);
void suma_elementos(double *A,double *B, int r,int N, double *sumA, double *sumB);
void suma_matrices(double *A,double *B, double *R, int r,int N);
void crearIdentidad(double *S, int sizeBlock, int sizeMatrix,int N,int r);
void crearMatriz(double *S, int sizeMatrix);
void imprimeMatriz(double *S,int N,int r);
void imprimeVector(double *S, int sizeMatrix);


int main (int argc, char *argv[]){

  double *A; // Matriz A
  double *B; // Matriz B
  double *C; // Matriz C
  double *D; // Matriz D
  double *DB; // Matriz resultante DB
  double *dB; // Matriz resultante AB
  double *bC; // Matriz resultante AC
  double *M; // Matriz resultante M
  double *AM; // Matriz resultante AM
  double timetick;
  int check=1;

  //El tamano de la matriz sera n= N*r , donde N y r se reciben
  //por parametro se tendran N*N bloques de r*r cada uno

  if (argc < 4){
    printf("\n Falta un parametro ");
    printf("\n 1. Cantidad de bloques por dimension ");
    printf("\n 2. Dimension de cada bloque ");
    printf("\n 3. 0/1 para imprimir/no imprimir resultados ");
    return 0;
  }

  int N = atoi(argv[1]);
  int r = atoi(argv[2]);
  int imprimir=atoi(argv[3]);

  int n = N*r; //dimension de la matriz
  double total = (double)1/(n*n); //cantidad total de elementos de la matriz
  int sizeMatrix=n*n; //cantidad total de datos matriz
  int sizeBlock=r*r; //cantidad total de datos del bloque
  double Dsum = 0; // promedio de D
  double Bsum = 0; // promedio de B
  double Dprom;
  double Bprom;
  int i;

  A= (double *)malloc(sizeMatrix*sizeof(double)); //aloca memoria para A
  B= (double *)malloc(sizeMatrix*sizeof(double)); //aloca memoria para B
  C= (double *)malloc(sizeMatrix*sizeof(double)); //aloca memoria para C
  D= (double *)malloc(sizeMatrix*sizeof(double)); //aloca memoria para D
  DB= (double *)malloc(sizeMatrix*sizeof(double)); //aloca memoria para DB
  dB= (double *)malloc(sizeMatrix*sizeof(double)); //aloca memoria para AB
  bC= (double *)malloc(sizeMatrix*sizeof(double)); //aloca memoria para AC
  M= (double *)malloc(sizeMatrix*sizeof(double)); //aloca memoria para M resultado
  AM= (double *)malloc(sizeMatrix*sizeof(double)); //aloca memoria para N resultado

  crearMatriz(A, sizeMatrix);			//Inicializa A
  crearIdentidad(B,sizeBlock,sizeMatrix,N,r); //Inicializa B como matriz identidad
  crearMatriz(C, sizeMatrix); //Inicializa C
  crearMatriz(D, sizeMatrix); //Inicializa D

  //Empieza procesamiento
  timetick = dwalltime();

  // Multiplica D*B
  producto(D,B,DB,r,N,sizeMatrix,sizeBlock);

  // Suma los elementos de D y B y los guarda en Dprom y Bprom
  suma_elementos(D,B,r,N,&Dprom, &Bprom);

  // Calcula el promedio (siendo total el inverso del total)
  Dprom = Dprom * total;
  Bprom = Bprom * total;

  // Multiplica d*B y b*C
  producto_por_un_escalar(Dprom, B, dB, r, N);
  producto_por_un_escalar(Bprom, C, bC, r, N);

  // Suma dB y bC y luego multiplica A por esa suma
  suma_matrices(dB, bC, M, r, N);
  producto(A, M, AM, r, N, sizeMatrix, sizeBlock);

  // Suma las dos matrices resultantes
  suma_matrices(AM, DB, M, r, N);

  printf("Tiempo en segundos %f \n", dwalltime() - timetick);
  //tiempo

  if (imprimir == 1){
    printf("\n\n  A (como esta almacenada): \n" );
    imprimeVector(A, sizeMatrix);

    printf("\n\n  B (como esta almacenada): \n" );
    imprimeVector(B,sizeMatrix);

    printf("\n\n  C (como esta almacenada): \n" );
    imprimeVector(C,sizeMatrix);

    printf("\n\n  D (como esta almacenada): \n" );
    imprimeVector(D,sizeMatrix);

    printf("\n\n  A: \n" );
    imprimeMatriz(A,N,r);

    printf(" \n\n B: \n" );
    imprimeMatriz(B,N,r);

    printf("\n\n  C: \n" );
    imprimeMatriz(C,N,r);

    printf("\n\n  D: \n" );
    imprimeMatriz(D,N,r);

    printf("\n\n Promedios: \n");
    printf(" B: %lf | D: %lf", Bprom, Dprom);

    printf("\n\n Resultado M: \n");
    imprimeMatriz(M, N, r);
  }

  free(A);
  free(B);
  free(C);
  free(D);
  free(DB);
  free(dB);
  free(bC);
  free(M);
  free(AM);

 return 0;
} //FIN MAIN


//SOLO PARA MATRICES DE IGUAL DIMENSION DE BLOQUES (N)
void producto(double *A,double *B,double *C, int r,int N,int sizeMatrix, int sizeBlock){
   int I,J,K,i,j,k;
   int despA, despB, despC,desp;

  for (i=0; i<sizeMatrix ;i++)
	  C[i]=0.0;

	for (I=0;I<N;I++){
		for (J=0;J<N;J++){
			despC = (I*N+J)*sizeBlock;
			for (K=0;K<N;K++){
				despA = (I*N+K)*sizeBlock;
				despB = (K*N+J)*sizeBlock;
				for (i=0;i<r;i++){
					for (j=0;j<r;j++){
						desp = despC + i*r+j;
						for (k=0;k<r;k++){
							C[desp] += A[despA + i*r+k]*B[despB + k*r+j];
						};
					}
				};
			};
		};
	};
}

//SOLO PARA MATRICES DE IGUAL DIMENSION DE BLOQUES (N)
void suma_elementos(double *A,double *B, int r,int N, double *sumA, double *sumB){
  int I,J,K,i,j,k;
  int desp;

  for (I= 0; I< N; I++){
    //para cada fila de bloques (I)
    for (i= 0; i< r; i++){
      for(J=0;J<N;J++){
		    desp=(I*N+J)*r*r;
	      for (j=0;j<r;j++){
	        // printf("%f ",S[despB+ i*r+j]);
          *sumA += A[desp+ i*r+j];
          *sumB += B[desp+ i*r+j];
	      };//end for j
	    };//end for J
    };//end for i
  };//end for I
}

//SOLO PARA MATRICES DE IGUAL DIMENSION DE BLOQUES (N)
void suma_matrices(double *A,double *B, double *R, int r,int N){
  int I,J,K,i,j,k;
  int desp;

  for (I= 0; I< N; I++){
    //para cada fila de bloques (I)
    for (i= 0; i< r; i++){
      for(J=0;J<N;J++){
		    desp=(I*N+J)*r*r;
	      for (j=0;j<r;j++){
          R[desp+ i*r+j]= A[desp+ i*r+j] + B[desp+ i*r+j];
	      };//end for j
	    };//end for J
    };//end for i
  };//end for I
}

//Multiplica toda la matriz por un valor dado
void producto_por_un_escalar(double valor, double *A, double *R, int r,int N){
  int I,J,K,i,j,k;
  int desp;

  for (I= 0; I< N; I++){
    //para cada fila de bloques (I)
    for (i= 0; i< r; i++){
      for(J=0;J<N;J++){
		    desp=(I*N+J)*r*r;
	      for (j=0;j<r;j++){
          R[desp+ i*r+j]= A[desp+ i*r+j] * valor;
	      };//end for j
	    };//end for J
    };//end for i
  };//end for I
}

void crearIdentidad(double *S, int sizeBlock, int sizeMatrix,int N,int r){
//Inicializa la matriz S como una matriz identidad
//pone cada bloque en 0, y a los bloques diagonales pone 1 en su diag. interna

//inicializa en cero la matriz
  int i,j;
  for (i=0; i<sizeMatrix ;i++){
	  S[i]=0.0;
  };//end for j

//inicializa los N bloques de la diagonal como identidad
  for (i=0; i<sizeMatrix; i=i+(N+1)*sizeBlock){
	//en i commienza el bloque a actualizar
	  for (j=0; j<sizeBlock; j=j+r+1){
		  S[i+j]= 1.0;
	  }
  };//end for i
}

void crearMatriz(double *S, int sizeMatrix){
  int i;
  for(i=0 ;i<sizeMatrix;i++){
	S[i] = rand()%10;
  };//end i
}

void imprimeVector(double *S, int sizeMatrix){
  int i;
  printf("\n ");
  for(i=0 ;i<sizeMatrix;i++)
	printf(" %f " ,S[i]);

  printf("\n\n ");
}


void imprimeMatriz(double *S,int N,int r){
// Imprime la matriz pasada por parametro
// N es la cantidad de bloques, r dimension de cada bloque
  int i,j,I,J,despB;

  printf("Contenido de la matriz: \n" );
  for (I= 0; I< N; I++){
    //para cada fila de bloques (I)
    for (i= 0; i< r; i++){
       for(J=0;J<N;J++){
		   despB=(I*N+J)*r*r;
	  for (j=0;j<r;j++){
	     printf("%f ",S[despB+ i*r+j]);

	   };//end for j
	};//end for J
        printf("\n ");
     };//end for i

  };//end for I
  printf(" \n\n");
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
