#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> inp;
    int tmp;

    cout << "Enter \"RETURN\" then \"CTRL + D\" to exit input" << endl;

    // input module:
    while(cin >> tmp){
        inp.push_back(tmp);
    }
    // calculate module: print the sum of each pair of adjacent elements
    for(auto i = 0; i < inp.size() - 1; i++){
        cout << inp[i] + inp[i + 1] << " ";
    }
    cout << endl;

    cout << "Enter \"RETURN\" then \"CTRL + D\" to exit input" << endl;

    // input module:
    while(cin >> tmp){
        inp.push_back(tmp);
    }
    // calculate module: print the sum of the fst and lst elements and so on
    for(auto i = 0; i < inp.size(); i++){
        cout << inp[i] + inp[inp.size() - 1 - i] << " ";
    }
    cout << endl;

    return 0;
}