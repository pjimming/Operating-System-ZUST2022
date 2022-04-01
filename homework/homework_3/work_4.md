#### 代码
```c
/*
 * Author: 潘江明
 * CreateTime: 2022-3-8
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int a = 1, b = 0, p;

    if ((p = fork()) == 0) {    // son
        int n = atoi(argv[1]);

        if (n <= 0) {
            printf("The parameter input error.\n");
        } else {
            for (int i = 0; i < n; i++) {
                int t = b;
                b += a;
                a = t;
            }

            printf("%d\n", b);
        }
    } else {
        wait(NULL);
    }

    return 0;
}
```

#### 运行截图

![](https://mooc-image.nosdn.127.net/8c151031f92542c08ada00638a5d6fad.png)