/* Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 4 C code that takes in 2 args for buffer size and file name and then reads and WRITEs using them.
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) { 
char buffer[atoi(argv[2])];
FILE *fp;
FILE *wp;
fp = fopen(argv[1], "rb");


// char *str2 = malloc(strlen(argv[1]+5));
// strcpy(str2, argv[1]);

char arr[30];
sprintf(arr,"%s.sout",argv[1]);
    
wp = fopen(arr, 1, "wb");


while (fread(buffer, sizeof(buffer), 1, fp)){
    fwrite(buffer,sizeof(buffer),1, wp);
}
fclose(fp);
fclose(wp);
return 0;
}
