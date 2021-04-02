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

    Person(int val, int height)
    {
        age = val;
        height_ = new int(height);
        cout << "Person 有参构造函数的调用" << endl;
    }

    //拷贝构造函数，拷贝一个已有对象的属性, const确保只读，并且只能用引用的方式传参
    Person(const Person &person)
    {
        //将传入的对象的所有属性，拷贝过来。
        age = person.age;
        height_ = new int(*person.height_); //深拷贝，重新在堆区分配内存空间
        cout<< "Person 拷贝构造函数的调用" << endl;
    }

    //析构函数，没有返回值，不用写void
    //函数名和类名相同，在名称前加 ~
    //析构函数没有参数，不可以重载
    ~Person()
    {
        //析构函数，将堆区开辟的数据做释放操作
        if(height_ != nullptr)
        {
            delete height_;
            height_ = nullptr;
        }
        cout << "Person 析构函数的调用" << endl;
    }

public:
    int age;
    int *height_;
};

// 深拷贝和浅拷贝
void test01()
{
    Person person(18, 160);
    Person person2(person);

    cout << "p1的年龄为： " << person.age <<  "身高为： " << *person.height_  << endl;
    cout << "p2的年龄为： " << person2.age << "身高为： " << *person2.height_  << endl;



}


int main()
{
    test01();
    return 0;
}