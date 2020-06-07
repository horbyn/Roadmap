#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;

    cin >> inp;
    // while()
    // int i = 0;
    // while(inp[i]){
    //     inp[i] = 'X';
    //     cout << inp[i];
    //     ++i;
    // }

    // for()
    for(int i = 0; inp[i]; i++){
        inp[i] = 'X';
        cout << inp[i];
    }

    cout << endl;

    return 0;
}