#include <iostream>
#include <vector>

using namespace std;

int main(){
    int arr_builtin[5] = {};
    vector<int> arr_vec{ 0, 1, 2, 3, 4 };

    cout << "Print the vector: " << endl;
    for(auto i : arr_vec)    cout << i << " ";
    cout << endl;
    for(int i = 0; i < 5; ++i)
        arr_builtin[i] = arr_vec[i];
    cout << "Print the built-in array: " << endl;
    for(auto i : arr_builtin)    cout << i << " ";
    cout << endl;

    return 0;
}