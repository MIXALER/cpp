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
    Person& AddAge(Person person)
    {
        this->age += person.age;
        return *this; // 链式编程
    }
};

void test01()
{
    Person person(18);
    cout << person.age << endl;

}

void test02()
{
    Person person1(10);
    Person person2(10);
    person2.AddAge(person1).AddAge(person1).AddAge(person1);
    cout << "person2的年龄 ： " << person2.age << endl;
}

int main()
{
    test02();
    return 0;
}