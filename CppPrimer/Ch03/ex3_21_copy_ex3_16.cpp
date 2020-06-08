#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v1;
    cout << "(a) " << v1.size() << "; ";
    for(auto it = v1.begin();
        it != v1.end(); ++it)
        cout << *it;
    cout << endl;

    vector<int> v2(10);
    cout << "(b) " << v2.size() << "; ";
    for(auto it = v2.begin();
        it != v2.end(); ++it)
        cout << *it;
    cout << endl;

    vector<int> v3(10, 42);
    cout << "(c) " << v3.size() << "; ";
    for(auto it = v3.begin();
        it != v3.end(); ++it)
        cout << *it;
    cout << endl;

    vector<int> v4{10};
    cout << "(d) " << v4.size() << "; ";
    for(auto it = v4.begin();
        it != v4.end(); ++it)
        cout << *it;
    cout << endl;

    vector<int> v5{10, 42};
    cout << "(e) " << v5.size() << "; ";
    for(auto it = v5.begin();
        it != v5.end(); ++it)
        cout << *it;
    cout << endl;

    vector<string> v6{10};
    cout << "(f) " << v6.size() << "; ";
    for(auto it = v6.begin();
        it != v6.end(); ++it)
        cout << *it;
    cout << endl;

    vector<string> v7{10, "hi"};
    cout << "(g) " << v7.size() << "; ";
    for(auto it = v7.begin();
        it != v7.end(); ++it)
        cout << *it;
    cout << endl;

    return 0;
}