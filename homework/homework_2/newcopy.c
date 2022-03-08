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
    fdold = open(argv[1], 0);
    fdnew = creat(argv[2], 0666);

    copy(fdold, fdnew);

    close(fdold);
    close(fdnew);

    exit(0);
}

void copy(int old, int new) {
    int count;
    while ((count = read(old, buffer, sizeof buffer)) > 0) {
        write(new, buffer, count);
    }
}


