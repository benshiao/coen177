/* Name: Benjamin Shiao
# Date: 4/14/20
# Title: Lab3 – Pthreads and inter-process Communication – Pipes
# Description: Step five, a C program to implement the producer-consumer message communication using pipes. 
*/

/**************************
*   Lab3 - pipe()
**************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
// main
int main(int argc,char *argv[]){
  int  fds[2];
  char buff[60];
  int count;
  int i;
  pipe(fds);
  if (fork()==0){
      printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
      
      dup2(fds[1], 1);
      close(fds[0]);        
      execlp("grep", "grep", "root", NULL);
      
      exit(0);
  }
  else if(fork()==0){
      printf("\nReader on the downstream end of the pipe \n");
     
      dup2(fds[1], 1);
       close(fds[0]);
    

       scanf("%s", buff);
    
      //takes input that is "/etc/passwd" and pass into below
       execlp("cat", "cat", buff, NULL);//cat prints out file contents
     
      exit(0);
   }
  else{    
     close(fds[0]);
     close(fds[1]);
     wait(0);
     wait(0);
  }
return 0;
}
