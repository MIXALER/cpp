//
// Created by yuanh on 2021/4/28.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void myprint(int val)
{
    cout << val << endl;
}

int main()
{

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    for_each(v1.begin(), v1.end(), myprint);
    return 0;
}

