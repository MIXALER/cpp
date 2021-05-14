//
// Created by yuanh on 2021/4/3.
//

#ifndef LEARN_CPP_MEMBER_FUNCTION_AS_FRIEND_H
#define LEARN_CPP_MEMBER_FUNCTION_AS_FRIEND_H
#include <iostream>
#include <string>
using namespace std;

class Building;


class FriendClass
{
public:
    FriendClass();
    void visit(); //设置为友元成员函数

    void visit2();//设置为非友元成员函数

    Building *building;
};

class Building
{
    friend void FriendClass::visit();
public:
    string sit_room_;
    Building();
private:
    string bed_room_;
};

void test01();


#endif //LEARN_CPP_MEMBER_FUNCTION_AS_FRIEND_H
