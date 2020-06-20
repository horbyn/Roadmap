#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(){
    int arr1[5] = { 0, 1, 2, 3, 4 };
    int arr2[5] = { 0, 1, 2, 3, 4 };
    int arr3[5] = { 0, 1, 2, 3, 5 };
    int fsame = 0;
    int index;

    // array: arr1 & arr2
    cout << "The two array arr1 and arr2: " << endl;
    for(auto i : arr1)    cout << i << " ";
    cout << endl;
    for(auto i : arr2)    cout << i << " ";
    cout << endl;
    for(index = 0; index < 5; ++index)
        if(arr2[index] != arr1[index]){
            fsame = 0;
            break;
        }
    // Two arrays are same when all elements were passed inspection
    if(index == 5)    fsame = 1;
    cout << "are ";
    if(fsame)    cout << "equality." << endl;
    else    cout << "not equality." << endl;

    // array: arr1 & arr3
    cout << "The two array arr1 and arr3: " << endl;
    for(auto i : arr1)    cout << i << " ";
    cout << endl;
    for(auto i : arr3)    cout << i << " ";
    cout << endl;
    for(index = 0; index < 5; index++)
        if(arr3[index] != arr1[index]){
            fsame = 0;
            break;
        }
    // Two arrays are same when all elements were passed inspection
    if(index == 5)    fsame = 1;
    cout << "are ";
    if(fsame)    cout << "equality." << endl;
    else    cout << "not equality." << endl;

    vector<int> arr_vec1{ 0, 1, 2, 3, 4 };
    vector<int> arr_vec2{ 0, 1, 2, 3, 4 };
    vector<int> arr_vec3{ 0, 1, 2, 3, 5 };
    vector<int>::iterator it1 = arr_vec1.begin();
    vector<int>::iterator it2 = arr_vec2.begin();
    vector<int>::iterator it3 = arr_vec3.begin();

    // vector: vec1 & vec2
    cout << "The two vectors arr_vec1 and arr_vec2: " << endl;
    for(auto i : arr_vec1)    cout << i << " ";
    cout << endl;
    for(auto i : arr_vec2)    cout << i << " ";
    cout << endl;
    for(; it1 != arr_vec1.end() && it2 != arr_vec2.end();
        ++it1, ++it2)
        if(it1 != it2){
            fsame = 0;
            break;
        }
    // Two vectors are same when all elements were passed inspection
    if(it1 == arr_vec1.end())    fsame = 1;
    cout << "are ";
    if(fsame)    cout << "equality." << endl;
    else    cout << "not equality." << endl;

    // vector: vec1 & vec3
    it1 = arr_vec1.begin();
    cout << "The two vectors arr_vec1 and arr_vec3: " << endl;
    for(auto i : arr_vec1)    cout << i << " ";
    cout << endl;
    for(auto i : arr_vec3)    cout << i << " ";
    cout << endl;
    for(; it1 != arr_vec1.end() && it3 != arr_vec3.end();
        ++it1, ++it3)
        if(it1 != it3){
            fsame = 0;
            break;
        }
    // Two vectors are same when all elements were passed inspection
    if(it1 == arr_vec1.end())    fsame = 1;
    cout << "are ";
    if(fsame)    cout << "equality." << endl;
    else    cout << "not equality." << endl;

    return 0;
}