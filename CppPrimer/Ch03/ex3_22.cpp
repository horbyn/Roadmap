#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> text;
    string paragraph;

    cout << "Enter \"RETURN\" then \"CTRL + D\" to exit input" << endl;

    while(getline(cin, paragraph)){
        text.push_back(paragraph);
    }

    for(auto it = text.begin();
        it != text.end() && !it->empty(); ++it)
    {
        for(auto it2 = it->begin();
            it2 != it->end(); ++it2)
            *it2 = toupper(*it2);
        cout << *it;
    }
    cout << endl;

    return 0;
}