/* Name: Benjamin Shiao
# Date: 4/14/20
# Title: Lab3 – Pthreads and inter-process Communication – Pipes
# Description: Step four, a C program meant to implement the shell command:  cat /etc/passwd | grep root
*/

/*Sample C program for Lab assignment 3*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//main
int main() {
   int fds[2];
   pipe(fds);
   /*child 1 duplicates downstream into stdin */
   if (fork() == 0) {
       dup2(fds[0], 0);
       close(fds[1]);
     //cant put in 2 arguements like below, 1st program (grep), 2nd (grep), 3rd is pointer to list of strings( where root is)
      char myString[1][14] = { "root"}; 

       execlp("grep", "grep", myString);//grep searches for smth with root in it
   }
   /*child 2 duplicates upstream into stdout */
   else if (fork() == 0) {
       dup2(fds[1], 1);
       close(fds[0]);
      //takes input that is "/etc/passwd" and pass into below
       execlp("cat", "cat", 0);//cat prints out file contents
   }
   else {  /*parent closes both ends and wait for children*/
       close(fds[0]);
       close(fds[1]);
       wait(0);
       wait(0);
   }
return 0;
}
