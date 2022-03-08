/*
 * Author: 潘江明
 * CreateTime: 2022-3-8
 */

#include<stdio.h>
main()
{
    int p1, p2;

    if ((p1=fork())==0) /*子进程创建成功*/
        putchar('b');
    else {
        if ((p2=fork())==0)
            putchar('c');  /*子进程执行*/
        else
            putchar('a');   /*父进程执行*/
    }

}

