//
// Created by yuanh on 2021/4/18.
//
#include <fstream>

using namespace std;

// 文本文件 写文件

void test_write()
{
    // 1. 包含头文件 fstream
    // 2. 创建流对象
    ofstream ofs;
    // 3. 指定打开方式
    ofs.open("test.txt", ios::out);
    // 4. 写内容
    ofs << "test test" << endl;
    ofs << "姓名： 张三" << endl;
    // 5.关闭流对象
    ofs.close();
}

int main()
{
    test_write();
    return 0;
}
