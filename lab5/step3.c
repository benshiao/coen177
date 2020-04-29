//Shared data: semaphore full, empty, mutex;
//pool of n buffers, each can hold one item
//mutex provides mutual exclusion to the buffer pool
//empty and full count the number of empty and full buffers
//Initially: full = 0, empty = n, mutex = 1
/* Name: Benjamin Shiao
# Date: 4/28/20
# Title: Lab5 – Synchronization using semaphores, lock, and condition variables
# Description: Modified version of file given for step1 to run using mutex locks instead of semaphores.
*/
// Thread Sychronization

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <fcntl.h>
#include <semaphore.h> 

#define NTHREADS 10
pthread_t threads[NTHREADS];
int buffer[10] = {11,22,33,44,55,66,77,88,99,100};
sem_t *mutex; 
sem_t *full; 
sem_t *empty; 

void* consume(void* arg) { 
 do{
 sem_wait(full);
  sem_wait(mutex); //entry section
  printf("Thread %d Entered Critical Section.. Consuming %d\n", (int)arg, buffer[(int)arg]); //critical section 
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
  printf("Thread %d Entered Critical Section.. producing item %d\n", (int)arg,buffer[(int)arg]); //critical section 
   sleep(1); 
  sem_post(mutex);
  sem_post(full); //exit section
 }while(1);
  return (NULL);
}

int main() { 
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
sem_unlink("mutex"); 
  return 0; 
} 



