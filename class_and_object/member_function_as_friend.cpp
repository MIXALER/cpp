//
// Created by yuanh on 2021/4/3.
//
#include "member_function_as_friend.h"

Building::Building()
{
    sit_room_ = "客厅";
    bed_room_ = "卧室";
}

void test01()
{
    FriendClass friendClass;
    friendClass.visit();
}

FriendClass::FriendClass()
{
    building = new Building;
}

void FriendClass::visit()
{
    cout << "访问" << building->sit_room_<<endl;
    cout << "访问" << building->bed_room_<<endl;
}

void FriendClass::visit2()
{
cout << "访问" << building->sit_room_ << endl;
}