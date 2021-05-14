//
// Created by yuanh on 2021/4/2.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    void ShowClassName()
    {
        cout << "this is Person class" << endl;
    }
    void ShowClassAge()
    {
// 解决名称冲突
        cout << "age = " << this->age << endl;
    }
    int age;
};

void test01()
{
    Person *p = nullptr;
//   p->ShowClassName();
    p->ShowClassAge();

}

//void test02()
//{
//    Person person1(10);
//    Person person2(10);
//    person2.AddAge(person1).AddAge(person1).AddAge(person1);
//    cout << "person2的年龄 ： " << person2.age << endl;
//}
//常函数

int main()
{
    test01();
    return 0;
}