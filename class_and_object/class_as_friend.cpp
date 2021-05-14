//
// Created by yuanh on 2021/4/3.
//

#include <iostream>
#include <string>
using namespace std;

class Building
{
    //设置为友元类
    friend class FriendClass;
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

class FriendClass
{
public:
    Building *building;
    FriendClass();
    void visit() // visit访问building中的属性
    {
        cout<<"访问" << building->sit_room_ << endl;
        cout<<"访问" << building->bed_room_ << endl;
    }
};
FriendClass::FriendClass()
{
    building = new Building;
}

void test01()
{
    FriendClass friendClass;
    friendClass.visit();
}

//类做友元
int main()
{
    test01();
    return 0;
}