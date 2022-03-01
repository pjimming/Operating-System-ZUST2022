#!/bin/bash

if test -d $1   # 目录
then
    echo "directoty"
else
    echo "not directory"
fi

if test -f $1   # 文件
then
    echo "file"
else
    echo "not file"
fi

if test -x $1   # 执行
then
    echo "excuteble"
else
    echo "Archive only"
fi

if test -r $1   # 读
then
    echo "readable"
else
    echo "unreadable"
fi

if test -w $1   # 写
then
    echo "writable"
else
    echo "not writable"
fi

if test -s $1   # 是否为空
then
    echo "not empty"
else
    echo "empty"
fi
