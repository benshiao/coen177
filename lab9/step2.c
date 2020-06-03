/* Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 2 C code that reads a file with name from argv[1] with a buffer size 10,000
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) { 
    char buffer[10000];
    FILE *fp;
    fp = fopen(argv[1], "rb");
    while (fread(buffer, sizeof(buffer), 1, fp)){
    }
    fclose(fp);

}
