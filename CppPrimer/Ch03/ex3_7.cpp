#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;

    cin >> inp;
    for(char c : inp)
        c = 'X';
    for(char c : inp)
        cout << c;
    cout << endl;

    return 0;
}