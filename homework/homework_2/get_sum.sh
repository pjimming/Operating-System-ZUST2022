#!/bin/bash

result=0

num=1

while test $num -le $1
do
    result=`expr $result + $num`
    num=`expr $num + 1`
done

echo "result=$result"
