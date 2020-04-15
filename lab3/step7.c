/* Name: Benjamin Shiao
# Date: 4/14/20
# Title: Lab3 – Pthreads and inter-process Communication – Pipes
# Description: Step 7, based on step 6 code, creates 10 threads and prints their thread number and a variable number. Fixed so no inconsistent numbering.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int main() {
   int i;
   for (i = 0; i < NTHREADS; i++){
      int *i2 = malloc(sizeof(*i));
      *i2 = i;
       pthread_create(&threads[i], NULL, go, i2);
   }
   for (i = 0; i < NTHREADS; i++) {
      printf("Thread %d returned\n", i);
       pthread_join(threads[i],NULL);
   }
   printf("Main thread done.\n");
   return 0;
}
void *go(void *arg) {
printf("Hello from thread %d with iteration %d\n",  (int)pthread_self(), *(int
*)arg);
return 0;
}
