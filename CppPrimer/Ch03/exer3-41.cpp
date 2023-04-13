#include <iostream>
#include <vector>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void print_int_arr(int *arr, size_t size) {
    std::cout << "[ ";
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "]" << std::endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    const size_t len = NELEMS(arr);

    std::cout << "arr: ";
    print_int_arr(arr, len);

    std::cout << "vec_arr: [ ";
    std::vector<int > vec(std::begin(arr), std::end(arr));
    for (auto v: vec)
        std::cout << v << " ";
    std::cout << "]" << std::endl;

    return 0;
}
