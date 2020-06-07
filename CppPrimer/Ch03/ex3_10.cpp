#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;
    string ret;

    cin >> inp;
    for(auto c : inp)
        if(!ispunct(c))
            ret += c;
    for(auto c : ret)
        cout << c;
    cout << endl;

    return 0;
}