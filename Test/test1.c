#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *suma(void *arg1) {
	int aux1 = *(int*)arg1;
	int res = aux1 + aux1;
	printf(" SUMA -> %d\n", res);
	pthread_exit(NULL);
}

void *resta(void *arg1){
	int aux1 = *(int*)arg1;
	int res = aux1 - 1;
	printf(" RESTA -> %d\n", res);
	pthread_exit(NULL);
}

int main() {
	printf(" ----- TEST 1 -------- \n");
	printf(" -- Se tienen dos pthreads usando dos distintas funciones que acceden a la misma variable\n\n");

	int var1 = 10;

	pthread_t T1;
	pthread_t T2;	

	pthread_create(&T1, NULL, &suma, (void*)&var1);
	pthread_create(&T2, NULL, &resta, (void*)&var1);

	for(int i=0; i<100000; i++);

	return 0;
}
