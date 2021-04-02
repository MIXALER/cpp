//
// Created by yuanh on 2021/4/2.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    //传统的初始化操作
//    Person(int a, int b, int c)
//    {
//        m_A = a;
//        m_B = b;
//        m_C = c;
//    }

    //初始化列表
    Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {}
    int m_A;
    int m_B;
    int m_C;
};

// 深拷贝和浅拷贝
void test01()
{
    Person person(3,2,1);
    cout << person.m_A << person.m_B << person.m_C << endl;
}


int main()
{
    test01();
    return 0;
}