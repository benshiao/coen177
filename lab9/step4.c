/* Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 4 C code that takes in 2 args for buffer size and file name and then reads and WRITEs using them.
*/

char buffer[atoi(argv[2])];
FILE *fp;
FILE *wp;
fp = fopen(argv[1], "rb");


char *str2 = malloc(strlen(argv[1]+5));
strcpy(str2, argv[1]);

wp = fopen(strcat(str2, ".out"), 1, "wb");


while (fread(buffer, sizeof(buffer), 1, fp)){
    fwrite(buffer,sizeof(buffer),1, wp);
}
fclose(fp);
fclose(wp);
