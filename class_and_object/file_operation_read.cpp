//
// Created by yuanh on 2021/4/18.
//
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 文本文件 读文件

void test_write()
{
    // 1. 包含头文件 fstream
    // 2. 创建流对象
    ifstream ifs;
    // 3. 打开文件，并且判断是否打开成功,设定打开方式
    ifs.open("test.txt", ios::in);
    // 4. 读文件
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
//    第一种读取方式
//    char buffer[1024] = {0};
//    while (ifs >> buffer)
//    {
//        cout << buffer << endl;
//    }
//    第二种方式
//    char buffer[1024] = {0};
//    while (ifs.getline(buffer, sizeof(buffer)) )
//    {
//        cout << buffer << endl;
//    }
    //    第三种方式
    string buffer;
    while (getline(ifs, buffer))
    {
        cout << buffer << endl;
    }
    //    第四种方式
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }
    // 5.关闭流对象
    ifs.close();
}

int main()
{
    test_write();
    return 0;
}
