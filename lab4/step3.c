/* Name: Benjamin Shiao
# Date: 4/21/20
# Title: Lab4 – Developing multi-threaded applications
# Description: Step one original code threadhello
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

#define M 3
#define N 3
#define L 3
pthread_t threads[M];

double matrixA[N][M];
double matrixB[M][L];
double matrixC[M][M];

int main() {
    static int i;
    int k,j,r;
//filling in matrix A---------------------
    srand(time(NULL));
    for ( k = 0; k < N; k++){
	for (j = 0; j < M; j++){
		r = rand();
	    printf(" %5.5d  ",r);
	    matrixA[k][j] = r;
	    //printf(" kj %5.5d %5.5d ",k,j);
		
    srand(time(NULL));
	}
	    printf("\n");
    }
	printf("\n");

	    printf(" %10.5d ",matrixA[0][0]);
	    printf(" %10.5d ",matrixA[0][1]);
	    printf(" %10.5d ",matrixA[0][2]);
	    printf(" %10.5d ",matrixA[1][0]);
	    printf(" %10.5d ",matrixA[1][1]);
	    printf(" %10.5d ",matrixA[1][2]);
	    printf(" %10.5d ",matrixA[2][0]);
	    printf(" %10.5d ",matrixA[2][1]);
	    printf(" %10.5d ",matrixA[2][2]);
	
	printf("\n");
//filling in matrix B--------------------	
    srand(time(NULL));
    for (k = 0; k < M; k++){
	for (j = 0; j < L; j++){
	    matrixB[k][j] = rand();
	    printf(" %10.5d ",matrixB[k][j]);
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
	printf("Thread %d returned \n", i);
    }
    
    for ( k = 0; k < M; k++){
	for (j = 0; j < M; j++){
		printf(" %20.3d ",matrixC[k][j]);
	}
	printf("\n");
    }
    printf("Main thread done.\n");
}
void *go(void *arg) {
    	int k,j;
    	printf("Hello from thread %d with thread ID %d \n", *(int *)arg, (int)pthread_self());
	for ( j = 0; j < L; j++){
    	double temp = 0;
    	for ( k = 0; k < M; k++){
		temp += matrixA[*(int *)arg][k] * matrixB[k][j];
		//printf("---a:%d b:%d--",matrixA[*(int *)arg][k], matrixB[k][j]);
	}
    	matrixC[*(int *)arg][j] = temp;
      	}
	

    	return (NULL);
}
