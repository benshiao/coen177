/* Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 4 C code that takes in 2 args for buffer size and file name and then reads and WRITEs using them.
*/

char buffer[stoi(argv[2])];
FILE *fp;
FILE *wp;
fp = fopen(argv[1], "rb");


wp = fopen( <idk> );


while (fread(buffer, sizeof(buffer), 1, fp)){
    fwrite(buffer,sizeof(buffer),1, wp);
}
fclose(fp);
fclose(wp);
