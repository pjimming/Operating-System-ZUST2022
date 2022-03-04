#!/bin/bash
count=$#
cmd=echo
while [ $count -gt 0 ]
do
    cmd="$cmd \$$count"
    count=`expr $count - 1`
done
eval $cmd

