#include <iostream>
#include <vector>

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
    for(auto it = inp.cbegin();
        it != inp.cend() - 1; it++){
        cout << *it + *(it + 1) << " ";
    }
    cout << endl;

    cout << "Enter \"RETURN\" then \"CTRL + D\" to exit input" << endl;

    // input module:
    while(cin >> tmp){
        inp.push_back(tmp);
    }
    // calculate module: print the sum of the fst and lst elements and so on
    auto it_head = inp.cbegin();
    auto it_tail = inp.cend();
    for(auto it = it_head;
        it != it_head + (it_tail - it_head) / 2; ++it)
    {
        cout << *it + *(it_head + (it_tail - it) - 1) << " ";
    }
    cout << endl;

    return 0;
}