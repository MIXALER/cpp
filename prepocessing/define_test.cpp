//
// Created by yuanh on 2021/5/16.
//



#include "stdio.h"

#define DEBUG_PRINT printf("File %s is line %d:" \
                        " x=%d, y=%d, z=%d", \
                        __FILE__, __LINE__, \
                        x, y, z)

int main()
{
    int x = 3, y = 4, z = 5;
    x *= 2;
    y += x;
    z = x * y;
    DEBUG_PRINT;
    return 0;
}