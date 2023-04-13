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
    int arr[5]{};

    std::vector<int > vec{ 1, 2, 3, 4, 5 };
    std::cout << "vec_arr: [ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
        arr[i] = vec[i];
    }
    std::cout << "]" << std::endl;

    std::cout << "arr: ";
    print_int_arr(arr, NELEMS(arr));

    return 0;
}
