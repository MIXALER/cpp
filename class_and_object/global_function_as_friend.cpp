//
// Created by yuanh on 2021/4/3.
//
#include <iostream>
#include <string>
using namespace std;

class Building
{
    //设置为友元函数
    friend void Friend_function(Building *building);
public:
    string sit_room_;
    Building()
    {
        sit_room_ = "客厅";
        bed_room_ = "卧室";
    }
private:
    string bed_room_;

};

//全局函数
void Friend_function(Building *building)
{
    cout << "全局函数访问" << building->sit_room_ << endl;
    cout << "全局函数访问" << building->bed_room_ << endl;
}

void test01()
{
    Building building;
    Friend_function(&building);
}


int main()
{
    test01();
    return 0;
}
