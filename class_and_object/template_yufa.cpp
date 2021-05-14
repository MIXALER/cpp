//
// Created by yuanh on 2021/4/18.
//

#include <iostream>

using namespace std;

template<typename T>
void mySwap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 10;
    int b = 20;
    // 自动类型推导
//    mySwap(a, b);
    // 显示指定类型
    mySwap<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}