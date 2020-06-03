/* Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 2 C code that reads a file with a buffer size 10,000
*/
char buffer[10000];
FILE *fp;
fp = fopen(argv[1], "rb");
while (fread(buffer, sizeof(buffer), 1, fp)){
}
fclose(fp);


