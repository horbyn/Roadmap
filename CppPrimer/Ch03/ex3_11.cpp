#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;

    const string s = "Keep out!";
    for (auto &c : s){
        c = 'X';
        cout << c;
    }
    cout << endl;

    return 0;
}