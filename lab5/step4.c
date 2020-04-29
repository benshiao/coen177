
/* Name: Benjamin Shiao
# Date: 4/28/20
# Title: Lab5 – Synchronization using semaphores, lock, and condition variables
# Description: Program to solve producer consumer problem using semaphores. 
#Five producers and Five consumer threads are made.
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
pthread_mutex_t lock;
/*
*lock = 
  pthread_mutex_lock(&lock);
  unlock
pthread_mutex_unlock(&lock);

*/
void* consume(void* arg) { 
 do{
  pthread_mutex_lock(&lock); //entry section
  while(/*buffer is full*/){
    pthread_cond_wait(empty, mutex);
  }
  printf("Adding the %d item to buffer, %d\n", (int)arg, buffer[(int)arg]); //critical section 
   sleep(1); 
  
  
  pthread_cond_signal(full);
  pthread_mutex_unlock(&lock);
  
 }while(1);
  return (NULL);
} 
void* produce(void* arg) { 
 do{
  pthread_mutex_lock(&lock);
  while(/*buffer is empty*/){
    pthread_cond_wait(full, mutex);
  }
  printf("Removing %d item, %d\n", (int)arg,buffer[(int)arg]); //critical section 
   sleep(1); 
  
  
  pthread_cond_signal(empty);
  pthread_mutex_unlock(&lock);
  
 }while(1);
  return (NULL);
}

int main() { 
 pthread_mutex_destroy(&mutex);
  pthread_mutex_init(&lock, NULL);
 sem_unlink("full"); 
sem_unlink("empty"); 
sem_unlink("mutex"); 
full = sem_open("mutex", O_CREAT, 0644, 1);
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



