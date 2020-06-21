#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char cstr1[] = "hello, str1, ";
    char cstr2[] = "hi, str2!";
    char cstr3[100] = "";               // must be large enough

    cout << "The two strings: " << "\"" << cstr1 << "\""
        << " and " << "\"" << cstr2 << "\"" << endl;
    cout << "After copying the former to an empty string: " << endl;
    strcpy(cstr3, cstr1);
    cout << cstr3 << endl;

    cout << "After concatenation the later to the former: " << endl;
    strcat(cstr3, cstr2);
    cout << cstr3 << endl;

    return 0;
}