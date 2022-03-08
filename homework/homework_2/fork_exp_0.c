#include<stdio.h>
main()
{
    int p1;

    if ((p1=fork())==0) /*子进程创建成功*/
        puts("b");
    else
        puts("a");   /*父进程执行*/
}

