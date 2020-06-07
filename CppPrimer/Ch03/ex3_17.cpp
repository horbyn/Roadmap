#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> inp;
    string word;

    cout << "Enter \"RETURN\" then \"CTRL + D\" to exit input" << endl;

    // transform uppercase while read the characters;
    // append to "inp" with a space in the tail
    while(cin >> word){
        for(auto &index : word)    index = toupper(index);
        inp.push_back(word);
        inp.push_back(" ");
    }

    // output each letter, and increase "i" while meeting
    // the space;
    // output newline when "i" is equal of eight
    int i = 1;
    for(auto index : inp){
        if(index != " "){
            cout << index;
            if(i % 8 == 0)    cout << endl;
        }else{
            if(i % 8 != 0)    cout << " ";
            ++i;
        }
    }
    cout << endl;

    return 0;
}