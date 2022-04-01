#!/bin/bash
dir=$1 
shift 
while   [ $#   -gt  0 ]
do
    cp   $1   $dir
    shift
done

# 作用：把输入的所有文件复制到目标目录内
