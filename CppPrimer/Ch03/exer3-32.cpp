#include <iostream>

int main() {
    constexpr size_t SIZE = 10;
    int arr[SIZE];

    for (size_t i = 0; i < SIZE; ++i)
        arr[i] = i;
    
    int arr_copy[SIZE];
    for (size_t i = 0; i < SIZE; ++i) {
        arr_copy[i] = arr[i];
        std::cout << arr_copy[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}
