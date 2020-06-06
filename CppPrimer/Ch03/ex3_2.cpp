#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;

    // Read a line at a time
    // cout << "Please input a string: ";
    // while(getline(cin, inp)){
    //     cout << inp << endl;
    // }


    // Read a word at a time
    cout << "Please input a string: ";
    while(cin >> inp){
        cout << inp << endl;
    }

    return 0;
}