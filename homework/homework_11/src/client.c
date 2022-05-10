// author: 潘江明
// time: 2022/5/10
// client.c

// TO DO：
// client端向server端进程发送一个消息正文
// 为自己的进程标识pid且类型为1的消息，
// 然后接收来自服务器进程的消息，并在屏幕上显示：
// “Client receives a message from xxxx！”，
// 其中“xxxx”为服务器进程的进程标识。
// 最后接收server端发来的消息，
// 返回消息的类型是client端的进程标识，
// server端进程标识作为消息正文发送给client端

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGKEY 75

// msgget()  用来创建和访问一个消息队列
// msgsend() 把消息添加到消息队列中
// msgrcv()  用来从一个消息队列获取消息
// msgctl()  控制消息队列

struct msg_st
{
    long type;      // 消息类型
    char text[256]; // 消息正文
};

void main()
{
    struct msg_st data;
    int msgid = -1, pid, *p;

    // 创建消息队列
    msgid = msgget(MSGKEY, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        printf("msgget error\n"); // 创建失败
        exit(0);
    }

    pid = getpid();       // 获得当前进程的pid
    p = (int *)data.text; // p指针指向data.text
    *p = pid;             // 等价于 data.text = pid;
    data.type = 1;        // 消息类型定义为 1

    // 向server端发送信息
    if (msgsnd(msgid, (void *)&data, sizeof(int), 0) == -1)
    {
        printf("msgsnd error\n");
        exit(0);
    }

    // 接收server发来的信息
    if (msgrcv(msgid, (void *)&data, 256, pid, 0) == -1)
        printf("msgrcv error\n");

    // 接收到信息后，data的值更改，因此 *p = data.text
    printf("Client receives a message from %d!\n", *p);
}