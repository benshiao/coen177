# Name: Benjamin Shiao
# Date: 6/2/20
# Title: Lab9 
# Description: Step 5 sh code that runs all 4 txt files with varying buffer sizes and threads as seen below, then reads and WRITEs using them.


for file in file1.txt file2.txt file3.txt file4.txt
do
            for buffer in 100 1000 10000 100000
            do
                      for thread in 2 8 32 64
                      do
                            echo "Step5 $file $buffer $thread"
                            time ./Step5 $file $buffer $thread
                            echo " "
                      done
            done
done
