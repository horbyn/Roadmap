#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> inp;
    int tmp;

    cout << "Enter \"RETURN\" then \"CTRL + D\" to exit input" << endl;

    while(cin >> tmp){
        inp.push_back(tmp);
    }

    for(auto it = inp.begin();
        it != inp.end(); ++it)
    {
        *it *= 2;
        cout << *it;
    }
    cout << endl;

    return 0;
}