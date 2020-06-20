#include <iostream>

using namespace std;

int main(){
    int arr[5] = { 0, 1, 2, 3, 4 };
    int *p = arr;

    for(int i = 0; i < 5; ++i)
        cout << *(p + i) << " ";
    cout << endl;

    return 0;
}