/* Name: Benjamin Shiao
# Date: 4/7/20
# Title: Lab2 – Programming in C and use of Systems Calls
# Description: Copy of original file given in step 1, edited for step 5 to have 7 total procsses
*/

/*Sample C program for Lab assignment 1*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
   pid_t  pid1, pid2, pid3;
   printf("\n Before forking.\n");
   pid1 = fork();
   pid2 = fork();
  printf("\t \t \t new process---%d -- %d \n", getpid(), getppid());
   return 0;
}
