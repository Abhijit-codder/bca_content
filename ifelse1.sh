#!/bin/bash
echo "Enter Num1 num2 num3"
read num1 num2 num3
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
    echo "$num1 is greatsest"
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
    echo "$num2 is greatest"
else
    echo "$num3 is greatest"
fi
