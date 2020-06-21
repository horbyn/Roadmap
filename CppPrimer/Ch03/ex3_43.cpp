#include <iostream>
#include <iterator>

using namespace std;

int main(){
    int arr[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    // case 1: range for()
    for(int (&row)[4] : arr)
        // row is equal of a one dimensional array
        for(int col : row)
            cout << col << " ";
    cout << endl;

    // case 2: for(subscripts)
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 4; ++j)
            cout << arr[i][j] << " ";
    cout << endl;

    // case 3: for(pointers)
    for(int (*row)[4] = begin(arr);
        row != end(arr);
        ++row)
        // row is a pointer to an array of four ints
        // *row is an array of four ints
        for(int *col = begin(*row);
            col != end(*row);
            ++col)
            cout << *col << " ";
    cout << endl;

    return 0;
}