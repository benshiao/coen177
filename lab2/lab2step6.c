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
/* main function with command-line arguments to pass */

void threadFunc(){
   printf("i am a thread");
}

int main(int argc, char *argv[]) {
   pid_t  pid;
   int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
   printf("\n Before forking.\n");
   pid = fork();
   if (pid == -1) {
       fprintf(stderr, "can't fork, error %d\n", errno);
   }
   if (pid){
       // Parent process
       for (i=0;i<100;i++) {
           printf("\t \t \t Parent Process %d \n",i);
           usleep(n);
       }
   }
   else{
       // Child process
       for (i=0;i<100;i++) {
           printf("Child process %d\n",i);
           usleep(n);
       }
   }
   return 0;
}