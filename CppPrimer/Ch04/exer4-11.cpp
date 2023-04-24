#include <iostream>

int main() {
    std::cout << "Please input 4 integer" << std::endl;
    int arr[4]{};

    int tmp{};
    for (size_t i = 0; i < 4; ++i)
        std::cin >> arr[i];
    
    std::cout << "a > b > c > d? ---> "
        << ((arr[0] > arr[1] && arr[1] > arr[2] && arr[2] > arr[3]) ? "true" : "false")
        << std::endl;

    return 0;
}
