
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
#include <signal.h>

#define NTHREADS 10
pthread_t threads[NTHREADS];
int buffer[10];
sem_t *mutex3; 
sem_t *full2; 
sem_t *empty2; 

void* consume(void* arg) { 
 do{
 sem_wait(full2);
  sem_wait(mutex3); //entry section
  int index = (rand()%10);
  printf("Consuming buffer[%d] : %d\n", index, buffer[index]); //critical section 
  //print
   sleep(1); 
  sem_post(mutex3); //exit section
  sem_post(empty2); //exit section
  
 }while(1);
  return (NULL);
} 
void* produce(void* arg) { 
 do{
  sem_wait(empty2);
  sem_wait(mutex3); //entry section
  int temp = 1+(rand()%10);
  int index = (rand()%10);
  printf("Producing item at buffer[%d]:  %d\n", index,temp); //critical section 
  //actually add
  buffer[index] = temp;
   sleep(1); 
  sem_post(mutex3);
  sem_post(full2); //exit section
 }while(1);
  return (NULL);
}
void cleanup(int sigtype){   
 sem_unlink("mutex3");    
 sem_unlink("full2");    
 sem_unlink("empty2");    
 printf("\n Terminating\n");    
 exit(0);
}
int main() { 
 signal(SIGINT,cleanup);
 srand(time(NULL));
sem_unlink("mutex3"); 
sem_unlink("full2"); 
sem_unlink("empty2"); 
mutex3 = sem_open("mutex3", O_CREAT, 0644, 1);
full2 = sem_open("full2", O_CREAT, 0644, 0);
empty2 = sem_open("empty2", O_CREAT, 0644, 10);
static int i;
for (i = 0; i < NTHREADS; i++){ //can try seperate numbers, like more than 1 con and 1 prod
   if(i%2==0)
    pthread_create(&threads[i], NULL, produce, NULL);
   else
    pthread_create(&threads[i], NULL, consume, NULL);
}
for (i = 0; i < NTHREADS; i++) {
   pthread_join(threads[i],NULL);
   printf("\t\t\tThread %d returned \n", i);
   }
printf("Main thread done.\n");
  return 0; 
} 



