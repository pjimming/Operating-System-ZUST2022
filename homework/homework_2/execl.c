/*
 * Author: 潘江明
 * CreateTime: 2022-3-8
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t childpid;
    childpid= fork();
    if (childpid < 0) {
        printf("Failed to fork\n");
    }
    if (childpid == 0) {
        execl("/bin/ls","ls","-l","/home/pjm/os_lesson");
    }
    if (childpid > 0) {
        wait(NULL);
    }

    return 0;
}
