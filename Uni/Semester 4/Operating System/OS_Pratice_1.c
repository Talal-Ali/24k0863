#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
    int fd[2];
    mkdir("file1");
    int readfile = open("file1", O_WRONLY);

    wait(NULL);
}