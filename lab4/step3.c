/* Name: Benjamin Shiao
# Date: 4/21/20
# Title: Lab4 – Developing multi-threaded applications
# Description: Step three using threads to calculate a matrix product
*/
/**************************************************************
*	threadHello.c - simple multi-threaded program.            *
*   compile with: >gcc -lp threadHello.c -o threadHello       *                                              *
**************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define NTHREADS 3

void *go(void *);

#define M 1024
#define N 1024
#define L 1024
pthread_t threads[M];

double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

int main() {
    static int i;
    int k,j;
//filling in matrix A---------------------
    srand(time(NULL));
    for ( k = 0; k < N; k++){
	for (j = 0; j < M; j++){
	    matrixA[k][j] = rand()%10;
	    printf(" %.1f ",matrixA[k][j]);
	}
	printf("\n");
    }
	
	printf("\n");
//filling in matrix B--------------------
    for (k = 0; k < M; k++){
	for (j = 0; j < L; j++){
	    matrixB[k][j] = rand()%10;
	    printf(" %.1f ",matrixB[k][j]);
	}
	printf("\n");
    }
//-------------------------------	
    for (i = 0; i < NTHREADS; i++){
       int *i2 = malloc(sizeof(*i2));
       *i2 = i;
       pthread_create(&threads[i], NULL, go, i2);
    }
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
	//printf("Thread %d returned \n", i);
    }
    printf("\n");
    for ( k = 0; k < N; k++){
	for (j = 0; j < L; j++){
		printf(" %.3f ",matrixC[k][j]);
	}
	printf("\n");
    }
    printf("Main thread done.\n");
}
void *go(void *arg) {
    	int k,j;
    	//printf("Hello from thread %d with thread ID %d \n", *(int *)arg, (int)pthread_self());
	for ( j = 0; j < L; j++){
    	double temp = 0;
    	for ( k = 0; k < M; k++){
		temp += matrixA[*(int *)arg][k] * matrixB[k][j];
	}
    	matrixC[*(int *)arg][j] = temp;
      	}
	

    	return (NULL);
}
