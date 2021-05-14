//
// Created by yuanh on 2021/4/3.
//

#include <iostream>
#include <string>

using namespace std;

//加号运算符重载

//通过全局函数实现重载

class Person
{
public:
    int A_;
    int B_;
    //通过成员函数实现重载

//    Person operator+(Person &person)
//    {
//        Person tmp;
//        tmp.A_ = this->A_ + person.A_;
//        tmp.B_ = this->B_ + person.B_;
//        return tmp;
//    }

};

Person operator+(Person person1, Person person2)
{
    Person tmp;
    tmp.A_ = person1.A_+ person2.A_;
    tmp.B_ = person1.B_ + person2.B_;
    return tmp;
}

Person operator+(Person person1, int num)
{
    Person tmp;
    tmp.A_ = person1.A_+ num;
    tmp.B_ = person1.B_ + num;
    return tmp;
}

void test01()
{
    Person person1;
    person1.A_ = 10;
    person1.B_ = 10;
    Person person2;
    person2.A_ = 10;
    person2.B_ = 10;

    Person person3;
    //成员函数重载本质调用
//    person3 = person1.operator+(person2);
    person3 = person1 + person2;

    //全局函数重载本质调用
//    person3 = operator+(person1, person2);

//运算符重载，也可以发生函数重载
    person3 = person1 + 10;


    cout << "person3: A:" << person3.A_ << " person3: B: " << person3.B_ << endl;
}

int main()
{
    test01();
    return 0;

}