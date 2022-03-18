#!/bin/bash
name=`ls *.sh`
for file in $name
do
    cp $file ./shell_list
done

cd shell_list && ls -Sl
