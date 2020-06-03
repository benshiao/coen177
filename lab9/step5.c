/* Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 5 C code that takes in 3 args for buffer size, number of threads, and file name and then reads and WRITEs using them.
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h> 
#include <fcntl.h>
#include <semaphore.h> 
#include <signal.h>
#include<stdio.h>
#include<stdlib.h>



pthread_t threads[atoi(argv[3])];
char buffer[atoi(argv[2])];
FILE *fp;

void* write_func(void* arg) { 
      FILE *wp;
      fp = fopen(argv[1], "rb");

      char *str2 = malloc(strlen(argv[1]+6));
      
      // char *str2 = malloc(strlen(argv[1]+5));
      // strcpy(str2, argv[1]);

      char arr[30];
      sprintf(arr,"%s.sout%d",argv[1],(int)arg);

      wp = fopen(arr, "wb");
             

      while (fread(buffer, sizeof(buffer), 1, fp)){
          fwrite(buffer,sizeof(buffer),1, wp);
      }
      fclose(fp);
      fclose(wp);
}

int main(int argc, char *argv[]) { 
      static int i;
      for (i = 0; i < atoi(argv[3]); i++){
          pthread_create(&threads[i], NULL, write_func, (void *)(size_t)i);
      }
      for (i = 0; i < atoi(argv[3]); i++) {
         pthread_join(threads[i],NULL);
         printf("\t\t\tThread %d returned \n", i);
      }
      return 0;
}
