/* Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 3 code that takes in 2 args for buffer size and file name and then reads them.
*/
char buffer[stoi(argv[2])];
FILE *fp;
fp = fopen(argv[1], "rb");
while (fread(buffer, sizeof(buffer), 1, fp)){
}
fclose(fp);
