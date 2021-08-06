---
title: c/c++ 内存分区模型
---

## c/c++内存分区模型

《程序员的自我修养》一书深入的探讨了程序编译，链接，装载和运行过程中的细节，本文简单的记录一下程序运行过程中内存存放的数据区域。

以前一直听说程序运行中的全局变量，局部变量，静态变量，堆区，栈区，一直没有搞明白他们的关系是什么。现在来简单的梳理一下。我是初学者，不对的地方请指正。

首先分为四个大的区域：

### 代码区

程序编译后，生成可执行程序，未执行该程序前分为两个区域

代码区：

存放cpu执行的机器指令

代码区共享的

只读

存放函数体的**二进制**代码，由操作系统进行管理

### 全局区

存放全局变量和静态变量以及常量（const)

全局变量和静态变量存放在全局区

全局区还包含了常量区，字符串常量和其他常量（const）也存放于此。

该区域的数据在程序结束后由操作系统释放

### 栈区

由编译器自动分配和释放，因此不要返回局部变量的地址，栈区开辟的数据由编译器自动释放。

函数的形参

声明在函数中的局部变量

用register声明的局部变量或函数形参。

### 堆区

由程序员分配和释放，若程序员不释放（就是垃圾），程序结束时由操作系统回收。

c++中主要利用new再堆区开辟内存，释放用delete，c中用malloc和free。



```c++
#include <iostream>

struct Node
{
    int val;
    Node* next;
    Node(int val, Node* next) : val(val), next(next) {}
};

using namespace std;
//全局变量，定义在函数体之外的变量
int global_a = 0;
int global_b = 0;
// 全局变量加上静态存储期声明
static int static_global_a = 0;
static int static_global_b = 0;
//全局常量
const int kGlobalIntA = 0;
const int kGlobalIntB = 0;

int main() {
    // 局部变量，定义在函数体中
    int local_a = 0;
    int local_b = 0;
    // 局部变量加上静态存储期声明
    static int static_local_a = 0;
    static int static_local_b = 0;
    // 局部常量
    const int kLocalA = 0;
    const int kLocalB = 0;

    string kStrA = "see memory distribution A";
    string kStrB = "see memory distribution B";
	// new分配堆上的空间
    Node* p_Node_local_a = new Node(8, nullptr);
    Node* p_Node_local_b = new Node(10, nullptr);


    cout << "全局变量global_a的地址是： " << &global_a << endl;
    cout << "全局变量global_b的地址是： " << &global_b << endl;
    cout << "静态全局变量static_global_a的地址是： " << &static_global_a << endl;
    cout << "静态全局变量static_global_b的地址是： " << &static_global_b << endl;
    cout << "静态局部变量static_local_a的地址是： " << &static_local_a << endl;
    cout << "静态局部变量static_local_b的地址是： " << &static_local_b << endl;
    cout << "全局常量kGlobalIntA的地址是： " << &kGlobalIntA << endl;
    cout << "全局常量kGlobalIntB的地址是： " << &kGlobalIntB << endl;

    cout << "局部变量local_a的地址是： " << &local_a << endl;
    cout << "局部变量local_b的地址是： " << &local_b << endl;
    cout << "局部常量kLocalA的地址是： " << &kLocalA << endl;
    cout << "局部常量kLocalB的地址是： " << &kLocalB << endl;
    cout << "局部字符串常量kStrA的地址是： " << &kStrA << endl;
    cout << "局部字符串常量kStrB的地址是： " << &kStrB << endl;

    cout << "局部变量p_Node_local_a的地址是： " << &p_Node_local_a << endl;
    cout << "局部变量p_Node_local_b的地址是： " << &p_Node_local_b << endl;
    cout << "p_Node_local_a所指向的地址是： " << p_Node_local_a << endl;
    cout << "p_Node_local_a所指向的结构体成员变量val的地址是： " << &p_Node_local_a->val << endl;
    cout << "p_Node_local_a所指向的结构体成员变量next的地址是： " << &p_Node_local_a->next << endl;
    cout << "p_Node_local_b所指向的地址是： " << p_Node_local_b << endl;
    cout << "p_Node_local_b所指向的结构体成员变量val的地址是： " << &p_Node_local_b->val << endl;
    cout << "p_Node_local_b所指向的结构体成员变量next的地址是： " << &p_Node_local_b->next << endl;

    delete p_Node_local_a;
    delete p_Node_local_b;

    return 0;
}
```
运行结果如下

**不同区域存放的数据，赋予不同的生命周期，编程更加灵活**。

可视化一个递归调用栈