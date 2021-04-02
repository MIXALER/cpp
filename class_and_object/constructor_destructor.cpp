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
        cout<< "Person 构造函数的调用" << endl;
    }

    //析构函数，没有返回值，不用写void
    //函数名和类名相同，在名称前加 ~
    //析构函数没有参数，不可以重载
    ~Person()
    {
        cout << "Person 析构函数的调用" << endl;
    }
};

//void test01()
//{
//    Person person; //在栈上的数据，test01执行完毕后，释放这个对象，调用析构函数。
//}

int main()
{
//    test01();
    Person person;
    return 0;
}