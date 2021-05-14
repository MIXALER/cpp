//
// Created by yuanh on 2021/4/3.
//

#include <iostream>
#include <string>

using namespace std;

//左移运算符重载

//通过全局函数实现重载

class Person
{
public:
    int A_;
    int B_;
};

ostream& operator<<(ostream &out, Person &person)
{
    cout << "A = " << person.A_ << " B = " << person.B_ << endl;
    return out;
}

void test01()
{
    Person person1;
    person1.A_ = 10;
    person1.B_ = 10;
    Person person2;
    person2.A_ = 10;
    person2.B_ = 10;
    cout  << person2 << endl;

}

int main()
{
    test01();
    return 0;

}