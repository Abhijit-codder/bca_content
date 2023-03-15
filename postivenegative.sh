#!/bin/bash
echo "enter any number for positv e,negative or zero"
read num
if [ $num -gt 0 ]
then 
   echo "$num is positive"
elif [ $num -lt 0 ]
then
   echo "$num is negative"
else 
   echo "$num is zero"
fi
