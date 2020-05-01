
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
#include <time.h>

#define NTHREADS 10
pthread_t threads[NTHREADS];
int buffer[10];
int counter;
int position;
int position2;
// sem_t *mutex; 
// sem_t *full; 
// sem_t *empty; 
pthread_mutex_t mutex;
pthread_mutex_t empty;
pthread_mutex_t full;

void* produce(void* arg) { 
 do{
  pthread_mutex_lock(&mutex); //entry section
  while(counter>=10/*buffer is full(check buffer array size)*/){
    pthread_cond_wait(&empty, &mutex);
  }
  int temp = 1+(rand()%10);
  //int index = (rand()%10);
  printf("Adding at buffer[%d] , %d\n", position, temp); //critical section 
  buffer[position] = temp;
  position = (position+1)%10;
   sleep(1); 
  
  counter++;
  pthread_cond_signal(&full);
  pthread_mutex_unlock(&mutex);
  
 }while(1);
  return (NULL);
} 
void* consume(void* arg) { 
 do{
  pthread_mutex_lock(&mutex);
  while(counter==0/*buffer is empty(check buffer array size, make counter)*/){
    pthread_cond_wait(&full, &mutex);
  }
  //int index = rand()%10;
  printf("Consuming buffer[%d] item, %d\n", position2,buffer[position2]); //critical section 
   sleep(1); 
  position2 = (position2+1)%10;
  counter--;
  
  pthread_cond_signal(&empty);
  pthread_mutex_unlock(&mutex);
  
 }while(1);
  return (NULL);
}

int main() { 
 counter = 0;
 srand(time(NULL));
 pthread_mutex_destroy(&mutex);
 pthread_mutex_destroy(&empty);
 pthread_mutex_destroy(&full);
  pthread_mutex_init(&mutex, NULL);
  pthread_mutex_init(&empty, NULL);
  pthread_mutex_init(&full, NULL);
 position = 0;
 position2 = 0;
//  sem_unlink("full"); 
// sem_unlink("empty"); 
// sem_unlink("mutex"); 
// full = sem_open("mutex", O_CREAT, 0644, 1);
// full = sem_open("full", O_CREAT, 0644, 0);
// empty = sem_open("empty", O_CREAT, 0644, 10);
 
 
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



