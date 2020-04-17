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

      close(fds[0]);
      for(i=1;i<argc;i++){
         write(fds[1],argv[i],strlen(argv[i]));
      }
      //new code:
      
      dup2(fds[1], 1);
      close(fds[0]);        
      execlp("grep", "grep", "root", NULL);
      
      exit(0);
  }
  else if(fork()==0){
      printf("\nReader on the downstream end of the pipe \n");
      //close(fds[1]);
    
      while((count=read(fds[0],buff,60))>0){
          for(i=0;i<count;i++){
              write(1,buff+i,1);
          }
          printf("\n");
      }  
    
    dup2(fds[1], 1);
      close(fds[0]);
    
    
      
//        char myString[] = "/etc/passwd";
//       char *ptr = myString;
    
    
      //takes input that is "/etc/passwd" and pass into below
       execlp("cat", "cat", "/etc/passwd", NULL);//cat prints out file contents
     
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
