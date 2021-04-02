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


//拷贝构造函数调用的三种时机

//1.使用一个已经创建完毕的对象来初始化一个对象
void test01()
{
    Person person1(20);
    Person person2(person1);

}
//2.值传递的方式给函数参数传值

void function(Person person)
{

}

void test02()
{
    Person person;
    function(person); // 这个时候会不会调用拷贝构造函数，会！ 因为将 person 传给 function 函数的时候是值传递，
    // 是一个拷贝，所以会自动调用拷贝构造函数，但是c++11标注似乎不让这么干，减少了不必要的拷贝
}

//3.值方式返回局部对象

Person function2()
{
    Person person1;
    cout << &person1 << endl;
    return person1; // function2 函数执行完会释放栈中存放的 person1 对象，但是要返回 person1 对象，相当于创建了一个新对象，并调用拷贝
                    //  函数拷贝 person1 来初始化这个对象
}
void test03()
{
    Person person = function2();
    cout << &person << endl;
}

int main()
{
    test03();
    return 0;
}
