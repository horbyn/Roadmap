#include <iostream>

int main() {
    constexpr size_t SIZE = 10;
    int arr[SIZE];

    for (size_t i = 0; i < SIZE; ++i)
        std::cout << (arr[i] = i, arr[i]) << " ";
    
    std::cout << std::endl;
    return 0;
}
