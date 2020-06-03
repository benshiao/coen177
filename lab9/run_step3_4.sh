  
#Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 3 and step 4 sh code that runs all 4 txt files and reads them for the different buffer sizes



for file in file1.txt file2.txt file3.txt file4.txt file5.txt
do
            for buffer in 100 1000 10000 100000
            do
                   echo "Step3 $file $buffer"
                   time ./Step3 $file $buffer
                   echo " "
            done
done
