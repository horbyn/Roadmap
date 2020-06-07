#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;

    cin >> inp;
    for(auto &c : inp)
        c = 'X';
    for(auto c : inp)
        cout << c;
    cout << endl;

    return 0;
}