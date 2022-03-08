/*
 * Author: 潘江明
 * CreateTime: 2022-3-8
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char buffer[2048];

int main(int argc, char **argv) {
    int fdold, fdnew;
    fdold = open(argv[1], 0);       // 打开要复制的文件
    fdnew = creat(argv[2], 0666);   // 新建文件

    copy(fdold, fdnew);     // 复制操作

    close(fdold);   // 关闭新文件
    close(fdnew);   // 关闭旧文件

    exit(0);        // 退出
}

void copy(int old, int new) {
    int count;
    // 把每次读出的字段写入新文件中，直到读完为止
    while ((count = read(old, buffer, sizeof buffer)) > 0) {
        write(new, buffer, count);
    }
}


