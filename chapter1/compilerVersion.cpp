//
// Created by yuanh on 2021/4/27.
//

#include <iostream>

int main()
{
    if (__cplusplus > 201703L)
        std::cout << "c++2a\n";
    else if (__cplusplus == 201703L) std::cout << "c++17\n";
    else if (__cplusplus == 201402L) std::cout << "c++14\n";
    else if (__cplusplus == 201103L) std::cout << "c++11\n";
    else if (__cplusplus == 199711L) std::cout << "c++98\n";
    else std::cout << "pre-standard c++\n";

    std::cout << "press any key to exit";
    std::cin.get();
    return 0;
}