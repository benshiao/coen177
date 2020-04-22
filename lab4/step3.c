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

#define NTHREADS 20

void *go(void *);

int M = 3;
int N = 3;
int L = 3;
pthread_t threads[M];

double matrixA[N][M];
double matrixB[M][L];

int main() {
    static int i;	
//filling in matrix A---------------------
    srand(time(NULL));
    for (int i = 0; i < N; i++)
	for (int j = 0; j < M; j++)
	    matrixA[i][j] = rand();
	
//filling in matrix B--------------------	
    srand(time(NULL));
    for (int i = 0; i < M; i++)
	for (int j = 0; j < L; j++)
	    matrixB[i][j] = rand();

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
    printf("Main thread done.\n");
}
void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", *(int *)arg, (int)pthread_self());
    return (NULL);
}
