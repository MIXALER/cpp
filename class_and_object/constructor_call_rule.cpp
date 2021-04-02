//
// Created by yuanh on 2021/4/2.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    //构造函数，没有返回值，不用写void
    //可以有参数，可以发生重载
    Person()
    {
        cout<< "Person 默认（无参）构造函数的调用" << endl;
    }

    Person(int val)
    {
        age = val;
        cout << "Person 有参构造函数的调用" << endl;
    }

    //拷贝构造函数，拷贝一个已有对象的属性, const确保只读，并且只能用引用的方式传参
    Person(const Person &person)
    {
        //将传入的对象的所有属性，拷贝过来。
        age = person.age;
        cout<< "Person 拷贝构造函数的调用" << endl;
    }

    //析构函数，没有返回值，不用写void
    //函数名和类名相同，在名称前加 ~
    //析构函数没有参数，不可以重载
    ~Person()
    {
        cout << "Person 析构函数的调用" << endl;
    }

private:
    int age;
};





int main()
{
    return 0;
}