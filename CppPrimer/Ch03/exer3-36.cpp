#include <iostream>
#include <vector>

int main() {
    const size_t SIZE_MAX_ARRAY = 5;
    int ia1[SIZE_MAX_ARRAY] = { 1, 2, 3, 4, 5 };
    int ia2[SIZE_MAX_ARRAY] = { 1, 2, 3, 4, 5 };

    size_t i = 0;
    for (; i < SIZE_MAX_ARRAY; ++i)
        if (ia1[i] != ia2[i])    break;
    if (i == SIZE_MAX_ARRAY)    std::cout << "array is equality" << std::endl;
    else    std::cout << "array is not equality" << std::endl;

    std::vector<int > va1(SIZE_MAX_ARRAY), va2(SIZE_MAX_ARRAY);
    for (size_t i = 0; i < SIZE_MAX_ARRAY; ++i) {
        va1[i] = va2[i] = i;
    }
    va1[3] = 100;

    if (va1 == va2)    std::cout << "vector is equality" << std::endl;
    else    std::cout << "vector is not equality" << std::endl;

    std::cout << std::endl;
    return 0;
}
