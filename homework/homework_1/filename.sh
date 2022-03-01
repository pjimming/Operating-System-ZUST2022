#!/bin/bash

PI=3.14159

echo “请输入圆的半径：”

read r

echo “圆的面积为：”

echo $PI*$r*$r | bc
