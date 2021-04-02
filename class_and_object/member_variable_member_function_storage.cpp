//
// Created by yuanh on 2021/4/2.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
    int age;
//public:
    static int height; // 不属于类的某一个对象，静态成员变量
    void func() {}
};

void test()
{
    Person person;
    //空对象占用内存空间为1
    // c++ 编译器给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象都有一个独一无二的内存地址
    cout << "size of person = "  << sizeof(person) << endl;
}

void test2()
{
    Person person;
//    Person::height = 10;
    cout << "size of person = "  << sizeof(person) << endl;
}

int main()
{
    test2();
    return 0;
}