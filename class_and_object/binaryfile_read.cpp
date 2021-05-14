//
// Created by yuanh on 2021/4/18.
//
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    char name_[64];
    int age_;
};

// 二进制文件 写文件
void test_write()
{
    // 1. 包含头文件 fstream
    // 2. 创建流对象
    ifstream ifs;
    // 3. 指定打开方式
    ifs.open("person.txt", ios::binary | ios::in);
    // 判断文件是否打开成功
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    // 4. 读内容
    Person p;
    ifs.read((char *) &p, sizeof(Person));

    cout << p.age_ << endl;
    cout << p.name_ << endl;

    // 5.关闭流对象
    ifs.close();
}

int main()
{
    test_write();
    return 0;
}
