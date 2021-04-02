//
// Created by yuanh on 2021/4/2.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(int age)
    {
// 解决名称冲突
        this->age = age;
    }
    int age;
};

void test01()
{
    Person person(18);
    cout << person.age << endl;
}

void test02()
{
    Person person1(10);
    Person
}

int main()
{
    test01();
    return 0;
}