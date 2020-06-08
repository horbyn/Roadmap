#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<unsigned> scores(11, 0);
    unsigned grade;

    cout << "Enter \"RETURN\" then \"CTRL + D\" to exit input" << endl;

    auto it_head = scores.begin();
    while(cin >> grade){
        if(grade <= 100){
            auto ind = grade / 10;
            ++*(it_head + ind);
        }
    }
    for(auto index : scores)
        cout << index << " ";
    cout << endl;
    
    return 0;
}