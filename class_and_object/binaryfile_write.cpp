//
// Created by yuanh on 2021/4/18.
//
#include <fstream>

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
    ofstream ofs;
    // 3. 指定打开方式
    ofs.open("person.txt", ios::binary | ios::out);
    // 4. 写内容
    Person p = {"张三", 18};
    ofs.write((const char *) &p, sizeof(Person));

    // 5.关闭流对象
    ofs.close();
}

int main()
{
    test_write();
    return 0;
}
