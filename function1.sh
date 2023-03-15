#!/bin/bash
add()
{
    echo "enter any tow number"
    read a
    read b
    sum=$(($a+$b))
    echo "$sum"
}
sub()
{
    sub=$(($a-$b))
    echo "$sub"
}
mult()
{
    mult=$(($a*$b))
    echo "$mult"
}
add
sub
mult
