//
// Created by yuanh on 2021/4/2.
//
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

void test01()
{
    // 括号法，显示法，隐式转换法
    // 括号法
//    Person person; //在栈上的数据，test01执行完毕后，释放这个对象，调用析构函数。
//    Person person1(10);
//    Person person2(person1);

    //显示法
    Person person3;// = Person();
    Person person4 = Person(10);
    Person person5 = Person(person4);
    // Person(10) 其实是匿名对象，没有名，特点：当前行语句执行完毕，系统会回收匿名对象
    // 不要利用利用拷贝构造函数初始化一个匿名对象，编译器会认为是一个对象声明

    // 隐式转换法
    Person person6 = 10; // 相当于 写了 Person person6 = Person(10);
    Person person7 = person6; // 其实在构建 string 对象的时候经常这样用 string str = "aaaa"; string str1 = str;


}


int main()
{
    test01();
    return 0;
}
