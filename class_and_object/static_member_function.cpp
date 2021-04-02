//
// Created by yuanh on 2021/4/2.
//

#include <iostream>
#include <string>

using namespace std;

//静态成员函数
//所有对象都共享同一个函数
//静态成员函数只能访问静态成员变量

class Person
{
public:
    static void function()
    {
        age = 100; //静态成员函数可以访问静态成员变量
//        height = 200; //静态成员函数不可以访问非静态成员变量，无法区分到底是哪个对象的 height
        cout<< "static void function 的调用" << endl;

    }

    // 静态成员函数也是有访问权限的

    static int age; //静态成员变量
    int height; // 非静态成员变量
private:
    static void function2()
    {

        cout<< "static void function 的调用" << endl;

    }
};

void test()
{
    //1.通过对象访问
    Person person;
    person.function();
    //2.通过类名访问
    Person::function();
}

int main()
{
    test();
    return 0;
}