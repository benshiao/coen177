# Name: Benjamin Shiao
# Date: 3/31/20
# Title: Lab1 – Unix/Linux Commands and Basic Shell Programming
# Description: This program computes a simple sh file that calculates the area of a circle given a radius and repeats on a given Yes/No. Works only for user=bshiao
#Sample shell programs for Lab assignment
#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "bshiao" ]
then
       echo "Now you can proceed!"
else
       echo "Check who logged in!"
       exit 1
fi
response="Yes"
while [ $response != "No" ]
do
       echo "Enter radius of circle: "
       read radius
       PI=3.14159
       area='expr $PI \* $radius \* $radius'
       echo "The area of the circle is $area"
       echo "Would you like to repeat for another circle [Yes/No]?"
       read response
done
