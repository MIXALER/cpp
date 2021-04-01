#include <iostream>
#include <climits>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    fstream fs;
    ofstream outClientFile("client.txt", ios::out);
    if(!outClientFile)
    {
        cerr<< "file could not be opened" << endl;
        exit( EXIT_FAILURE);
    }
    cout << "enter the count, name, and balance" << endl << "enter eof to end input.\n?";
    int acount;
    string name;
    double balance;
    while (cin>>acount>>name>>balance)
    {
        outClientFile<< acount<<' ' << name << ' ' << balance << endl;
        cout << "?";
    }
//    ifstream readfile(".CMakeLists.txt");
//    string name_2;
//    while (getline(readfile, name_2))
//    {
//        cout<<name_2<<endl;
//    }
    return 0;
}
