# Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 2 code that runs all 4 txt files and reads them with the standard buffer size

for file in file1.txt file2.txt file3.txt file4.txt
do
   echo "Step2 $file"
   time ./Step2 $file
   echo " "
done

