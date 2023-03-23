#include <iostream>

int main() {
    const size_t SIZE_MAX_ARRAY = 5;
    int ia[SIZE_MAX_ARRAY] = { 1, 2, 3, 4, 5 };

    std::cout << "origin array:" << std::endl;
    for (auto val : ia)
        std::cout << val << " ";

    int *p = ia;
    for (size_t i = 0; i < SIZE_MAX_ARRAY; ++i)
        p[i] = 0;
    std::cout << "\narray after revising:" << std::endl;
    for (auto val : ia)
        std::cout << val << " ";

    std::cout << std::endl;
    return 0;
}
