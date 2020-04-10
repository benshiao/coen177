/* Name: Benjamin Shiao
# Date: 4/7/20
# Title: Lab2 – Programming in C and use of Systems Calls
# Description: step 7, edited original file from step 1 so child process runs the ls command and that the parent parent process waits until the child process terminates before it exits
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
   int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
   printf("\n Before forking.\n");
   pid = fork();
   if (pid == -1) {
       fprintf(stderr, "can't fork, error %d\n", errno);
   }


   if (pid == 0){
      // Child process
      execlp("/bin/ls", "ls", NULL);
   }
   else{
       // Parent process
      wait(NULL);
       printf("Child Complete");
       exit(0);
   }
   return 0;
}
