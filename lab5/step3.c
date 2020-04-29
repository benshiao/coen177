
/* Name: Benjamin Shiao
# Date: 4/28/20
# Title: Lab5 – Synchronization using semaphores, lock, and condition variables
# Description: Program to solve producer consumer problem using semaphores. 
#Five producers and Five consumer threads are made.
*/
// Thread Sychronization

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h> 
#include <fcntl.h>
#include <semaphore.h> 

#define NTHREADS 10
pthread_t threads[NTHREADS];
int buffer[10];
sem_t *mutex; 
sem_t *full; 
sem_t *empty; 

void* consume(void* arg) { 
 do{
 sem_wait(full);
  sem_wait(mutex); //entry section
  int index = (rand()%10);
  printf("Consuming buffer[%d] : %d\n", index, buffer[(int)arg]); //critical section 
  //print
   sleep(1); 
  sem_post(mutex); //exit section
  sem_post(empty); //exit section
  
 }while(1);
  return (NULL);
} 
void* produce(void* arg) { 
 do{
  sem_wait(empty);
  sem_wait(mutex); //entry section
  int temp = 1+(rand()%10);
  int index = (rand()%10);
  printf("Producing item at buffer[%d]:  %d\n", index,temp); //critical section 
  //actually add
  buffer[(int)arg] = temp;
   sleep(1); 
  sem_post(mutex);
  sem_post(full); //exit section
 }while(1);
  return (NULL);
}

int main() { 
 srand(time(NULL));
sem_unlink("mutex"); 
sem_unlink("full"); 
sem_unlink("empty"); 
mutex = sem_open("mutex", O_CREAT, 0644, 1);
full = sem_open("full", O_CREAT, 0644, 0);
empty = sem_open("empty", O_CREAT, 0644, 10);
static int i;
for (i = 0; i < NTHREADS; i++){ //can try seperate numbers, like more than 1 con and 1 prod
   if(i%2==0)
    pthread_create(&threads[i], NULL, produce, (void *)(size_t)i);
   else
    pthread_create(&threads[i], NULL, consume, (void *)(size_t)i);
}
for (i = 0; i < NTHREADS; i++) {
   pthread_join(threads[i],NULL);
   printf("\t\t\tThread %d returned \n", i);
   }
printf("Main thread done.\n");
  return 0; 
} 



