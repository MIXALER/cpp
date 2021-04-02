//
// Created by yuanh on 2021/4/2.
//
#include <iostream>
#include <string>

using namespace std;

class Phone
{
public:
    string phone_name_;
    Phone(string phone_name)
    {
        phone_name_ = phone_name;
        cout << "Phone 的构造函数调用" << endl;
    }
    ~Phone()
    {
        cout <<" Phone 的析构函数调用" << endl;
    }
};

class Person
{
public:
    Person(string name, string phone_name) :person_name_(name), phone_(phone_name) //隐式转换法
    {
        cout << "Person 的构造函数调用";
    }
    ~Person()
    {
        cout << "Person的析构函数调用"<< endl;

    }
    string person_name_;
    Phone phone_;

};

void test()
{
    Person person("张三", "小米");
    cout << person.person_name_ <<endl <<person.phone_.phone_name_<< endl;
}
int main()
{
    test();
    return 0;
}

