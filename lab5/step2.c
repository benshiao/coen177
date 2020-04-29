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
sem_t *mutex; 
 pthread_mutex_t lock;

void* go(void* arg) { 
  //sem_wait(mutex); //entry section
  pthread_mutex_lock(&lock);
  printf("Thread %d Entered Critical Section..\n", (int)arg); //critical section 
   sleep(1); 
  //sem_post(mutex); //exit section
   pthread_mutex_unlock(&lock);
  return (NULL);
} 

int main() { 
//mutex = sem_open("mutex", O_CREAT, 0644, 1);
  pthread_mutex_init(&lock, NULL);
static int i;
for (i = 0; i < NTHREADS; i++)  
   pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
for (i = 0; i < NTHREADS; i++) {
   pthread_join(threads[i],NULL);
   printf("\t\t\tThread %d returned \n", i);
   }
printf("Main thread done.\n");
//sem_unlink("mutex"); 
  pthread_mutex_destroy(&mutex);
  return 0; 
} 
