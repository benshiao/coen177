/* Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 1 code that creates 4 txt files with random bytes for the sizes seen below
*/
#!/bin/bash
# cat /dev/random | head -c <bytecount>
cat /dev/random | head -c 100000 > file1.txt
cat /dev/random | head -c 1000000 > file2.txt
cat /dev/random | head -c 10000000 > file3.txt
cat /dev/random | head -c 100000000 > file4.txt

