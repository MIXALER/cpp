//
// Created by yuanh on 2021/4/3.
//

#include <iostream>
#include <string>

using namespace std;

//递增运算符重载

//自定义整型


class MyInteger
{
    friend ostream & operator<<(ostream &cout, MyInteger my_integer);
public:
    MyInteger()
    {
        num_ = 0;
    }
    //重载前置递增运算符，返回引用是对同一个数据做递增操作
    MyInteger& operator++()
    {
        num_++;
        return *this;
    }
    MyInteger operator++(int) //int代表占位参数，可以用于区分前置和后置递增，后置返回值，而不是值
    {
        //先记录值，再递增，最后返回记录值
        MyInteger temp = *this;
        num_++;
        return temp;
    }

private:
    int num_;
};

ostream & operator<<(ostream &cout, MyInteger my_integer)
{
    cout << my_integer.num_ << endl;
    return cout;
}



void test01()
{
    MyInteger my_integer;
    cout << ++my_integer << endl;
}

void test02()
{
    MyInteger my_integer;
    cout << my_integer++ << endl;
}

int main()
{
    test02();
    return 0;
}