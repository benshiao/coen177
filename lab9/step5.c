/* Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 4 C code that takes in 2 args for buffer size and file name and then reads and WRITEs using them.
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h> 
#include <fcntl.h>
#include <semaphore.h> 
#include <signal.h>


pthread_t threads[argv[3]];
char buffer[stoi(argv[2])];
FILE *fp;
FILE *wp;
fp = fopen(argv[1], "rb");


wp = fopen( <idk> );
/*
static int i;
for (i = 0; i < NTHREADS; i++){ //can try seperate numbers, like more than 1 con and 1 prod
   if(i%2==0)
    pthread_create(&threads[i], NULL, produce, (void *)(size_t)i);
   else
    pthread_create(&threads[i], NULL, consume, (void *)(size_t)i);
}
for (i = 0; i < NTHREADS; i++) {
   pthread_join(threads[i],NULL);
   printf("\t\t\tThread %d returned \n", i);
   }
   */

while (fread(buffer, sizeof(buffer), 1, fp)){
    fwrite(buffer,sizeof(buffer),1, wp);
}
fclose(fp);
fclose(wp);
