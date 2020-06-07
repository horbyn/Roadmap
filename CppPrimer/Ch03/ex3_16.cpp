#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v1;
    cout << "(a) " << v1.size() << "; ";
    for(auto index : v1)    cout << index;
    cout << endl;

    vector<int> v2(10);
    cout << "(b) " << v2.size() << "; ";
    for(auto index : v2)    cout << index;
    cout << endl;

    vector<int> v3(10, 42);
    cout << "(c) " << v3.size() << "; ";
    for(auto index : v3)    cout << index;
    cout << endl;

    vector<int> v4{10};
    cout << "(d) " << v4.size() << "; ";
    for(auto index : v4)    cout << index;
    cout << endl;

    vector<int> v5{10, 42};
    cout << "(e) " << v5.size() << "; ";
    for(auto index : v5)    cout << index;
    cout << endl;

    vector<string> v6{10};
    cout << "(f) " << v6.size() << "; ";
    for(auto index : v6)    cout << index;
    cout << endl;

    vector<string> v7{10, "hi"};
    cout << "(g) " << v7.size() << "; ";
    for(auto index : v7)    cout << index;
    cout << endl;

    return 0;
}