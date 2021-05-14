//
// Created by yuanh on 2021/5/8.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>

int main()
{
    srand((unsigned) time(0)); // 用当前时间作为随机数的种子

    for (int i = 0; i < 20; ++i)
    {

        int tmp = rand() % 10;
        printf("%d ", tmp);
    }
    return 0;
}