#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp1, inp2;

    // whether the strings are equal:
    // cout << "Please input two strings: ";
    // cin >> inp1 >> inp2;
    // if(inp1 == inp2){
    //     cout << "These two strings are equal!" << endl;
    // }else{
    //     if(inp1 > inp2)
    //         cout << "They aren't equal, but " << inp1 << " is larger" << endl;
    //     else
    //         cout << "They aren't equal, but " << inp2 << " is larger" << endl;
    // }


    // whether the strings have the same length:
    cout << "Please input two strings: ";
    cin >> inp1 >> inp2;
    if(inp1.size() == inp2.size()){
        cout << "These two strings have the same length!" << endl;
    }else{
        if(inp1.size() > inp2.size())
            cout << "Their length aren't same, but " << inp1 << " is longer" << endl;
        else
            cout << "Their length aren't same, but " << inp1 << " is longer" << endl;
    }

    return 0;
}