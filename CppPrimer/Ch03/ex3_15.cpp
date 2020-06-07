#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> inp;
    string tmp;

    cout << "Enter \"RETURN\" then \"CTRL + D\" to exit input" << endl;
    // input:
    while(cin >> tmp)
        inp.push_back(tmp);
    // output:
    for(auto i : inp)
        cout << i;
    cout << endl;

    return 0;
}