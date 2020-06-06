#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp1, inp2;

    // connect two srings:
    // cout << "Please input two strings: ";
    // cin >> inp1 >> inp2;
    // cout << inp1 + inp2 << endl;


    // separate strings by a space:
    cout << "Please input two strings: ";
    cin >> inp1 >> inp2;
    cout << inp1 + ' ' + inp2 << endl;

    return 0;
}