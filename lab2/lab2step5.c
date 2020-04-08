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
   pid_t  pid;
   printf("\n Before forking.\n");
   pid = fork();
   if(pid){
      fork();
   }else{
      fork();
      fork();
   }
  printf("\t \t \t new process--- \n");
   return 0;
}
