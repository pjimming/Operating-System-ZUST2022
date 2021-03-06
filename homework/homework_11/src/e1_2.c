// author: 潘江明
// time: 2022/5/6
// 通过signal()捕捉CTRL+C来中断两个子进程，最后中断父进程
// e1_2

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int wait_flag;

void stop()
{
    wait_flag = 0;
}

int main()
{
    int pid1, pid2;
    wait_flag = 1;
    signal(SIGINT, stop); // 按CTRL+C后，执行stop()函数

    while ((pid1 = fork()) == -1)
        ;

    if (pid1 > 0)
    {
        while ((pid2 = fork()) == -1)
            ;
        if (pid2 > 0)
        {
            wait_flag = 1;
            while (wait_flag == 1)
                ;                // 等待CTRL+C，wait_flag=0退出循环
            kill(pid1, SIGUSR1); // 向pid1发送SIGUSR1信号
            kill(pid2, SIGUSR2); // 向pid2发送SIGUSR2信号
            wait(0);             // 等待子进程
            wait(0);             // 等待子进程
            printf("Parent process is killed !!\n");
            exit(0);
        }
        else
        {
            wait_flag = 1;
            signal(SIGUSR2, stop);
            while (wait_flag == 1)
                ; // 等待CTRL+C，wait_flag=0退出循环
            printf("Child process 2 is killed by parent !!\n");
            exit(0);
        }
    }
    else
    {
        wait_flag = 1;
        signal(SIGUSR1, stop);
        while (wait_flag == 1)
            ;
        printf("Child process 1 is killed by parent !!\n");
        exit(0);
    }
}