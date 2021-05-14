//
// Created by yuanh on 2021/5/8.
//

#include <stdio.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}


int main()
{
    int a =2;
    int b = 3;
    printf("before swap: addr of a is : %p\n", &a);
    printf("before swap: addr of b is : %p\n", &b);
    printf("before swap: value of a is : %d\n", a);
    printf("before swap: value of b is : %d\n", b);
    swap2(&a, &b);
    printf("after swap: addr of a is : %p\n", &a);
    printf("after swap: addr of b is : %p\n", &b);
    printf("after swap: value of a is : %d\n", a);
    printf("after swap: value of b is : %d\n", b);
    return 0;
}