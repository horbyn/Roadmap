#include <iostream>
#include <vector>

using namespace std;

int main(){
    int arr_builtin[] = { 0, 1, 2, 3, 4 };
    vector<int> arr_vec(arr_builtin, arr_builtin + 5);

    cout << "Print the buili-in array: " << endl;
    for(auto i : arr_builtin)    cout << i << " ";
    cout << endl;
    cout << "Print the vector: " << endl;
    for(auto i : arr_vec)    cout << i << " ";
    cout << endl;

    return 0;
}