// author: 潘江明
// time: 2022/5/11
// shmread.c

// TO DO:
// 使用系统调用shmget()、shmat()和shmctl()，
// 用共享内存机制实现进程间的通信。
// 其中一个进程向共享内存中写入数据，
// 另一个进程从共享内存中读出数据并显示在屏幕上。

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SHMKEY 75

// shmget() 用来创建共享内存
// shmat()  用来启动对该共享内存的访问，
// 并把共享内存连接到当前进程的地址空间。
// shmctl() 用来控制共享内存

struct shm_st
{
    int type;       // 0：写  1：读
    char text[256]; // 消息正文
};

void main()
{
    void *shm = NULL;
    int shmid;
    struct shm_st *shared;

    // 创建共享内存
    shmid = shmget(SHMKEY, sizeof(struct shm_st), 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        printf("shmget error\n"); // 创建失败
        exit(0);
    }

    // 链接共享内存，开启访问
    shm = shmat(shmid, 0, 0); // shm指针指向当前进程的共享内存地址
    if (shm == (void *)-1)
    {
        printf("shmat error\n"); // 失败
        exit(0);
    }

    // 输出地址
    printf("Memory attached at %p\n", shm);

    shared = (struct shm_st *)shm; // shared指针指向共享内存所在的地址
    shared->type = 0;              // 修改当前权限为写状态
    while (1)
    {
        if (shared->type == 1) // 读状态
        {
            printf("You worte %s\n", shared->text);
            sleep(1);

            shared->type = 0; // 修改为写状态

            // 输入为end时退出
            if (strcmp(shared->text, "end") == 0)
            {
                break;
            }
        }
        else // 等待写进程写入消息
        {
            sleep(1);
        }
    }

    // 删除共享内存
    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        // 失败
        printf("shmctl error\n");
        exit(0);
    }
    else
    {
        // 成功
        printf("remove shm successful!!!\n");
    }
}