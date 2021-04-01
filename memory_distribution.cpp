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

const int kGlobalIntA = 0;
const int kGlobalIntB = 0;

int main() {
    // 局部变量，定义在函数体中
    int local_a = 0;
    int local_b = 0;
    // 局部变量加上静态存储期声明
    static int static_local_a = 0;
    static int static_local_b = 0;
    //常量,存放在栈区，具有自动存储期，由编译器自动分配和释放
    const int kLocalA = 0;
    const int kLocalB = 0;

    string kStrA = "see memory distribution A";
    string kStrB = "see memory distribution B";

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
