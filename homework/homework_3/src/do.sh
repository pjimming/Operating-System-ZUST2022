#! /bin/bash

# 在该脚本后面输入可执行文件名，即可运行十次输入的可执行文件

for ((i=1; i<=10; i++))
do
    echo
    ./$1
done
