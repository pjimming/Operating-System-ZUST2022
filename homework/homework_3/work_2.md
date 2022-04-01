1. 
```c
#include<stdio.h>
main()
{
    int p1;

    if ((p1=fork())==0) /*子进程创建成功*/
        puts("b");
    else
        puts("a");   /*父进程执行*/
}
```

![](https://mooc-image.nosdn.127.net/a84c03663c1c4e9689085b02cd965c23.png)

---

2. 
```c
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
```

![](https://mooc-image.nosdn.127.net/6a11ed933f5c4fdf9384998b76d85760.png)