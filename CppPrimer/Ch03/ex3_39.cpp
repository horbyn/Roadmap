#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    string str1("hello");
    string str2("hi");
    
    if(str1 > str2)
        cout << str1 << " is larger than " << str2 << endl;
    else
        cout << str1 << " is less than " << str2 << endl;

    char cstr1[] = "hello";
    char cstr2[] = "hi";

    if(strcmp(cstr1, cstr2) > 0)
        cout << cstr1 << " is larger than " << cstr2 << endl;
    else
        cout << cstr1 << " is less than " << cstr2 << endl;

    return 0;
}