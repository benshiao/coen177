/* Name: Benjamin Shiao
# Date: 4/7/20
# Title: Lab2 – Programming in C and use of Systems Calls
# Description: Step 6, edited file given in step 1 to run with threads instead of processes
*/

/*Sample C program for Lab assignment 1*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <pthread.h>
/* main function with command-line arguments to pass */

void *threadFuncParent(void * args){
   int *n = (int *)args;
   int i;
   for (i=0;i<100;i++) {
     printf("\t \t \t Parent Thread %d \n",i);
     usleep(*n);
   }  
   return;
}
void *threadFuncChild(void * args){
   int *n = (int *)args;
   int i;
   for (i=0;i<100;i++) {
     printf("Child Thread %d \n",i);
     usleep(*n);
   }  
   return;
}

int main(int argc, char *argv[]) {
   int n = atoi(argv[1]); // n microseconds to input from keyboard for delay
   printf("\n Before Thread.\n");
   pthread_t thread_id_parent, thread_id_child;
   
   pthread_create(&thread_id_parent, NULL, threadFuncParent, (void *)&n);
   pthread_create(&thread_id_child, NULL, threadFuncChild, (void *)&n);
   
   pthread_join(thread_id_parent, NULL);
   pthread_join(thread_id_child, NULL);
   
   printf("\n After Thread.\n");
   
   return 0;
}
