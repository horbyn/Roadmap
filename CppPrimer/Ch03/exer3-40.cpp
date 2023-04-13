#include <iostream>
#include <cstring>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void print_int_arr(char *arr, size_t size) {
    std::cout << "[ ";
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "]" << std::endl;
}

int main() {
    char arr1[] = "hello ", arr2[] = "world!";
    const size_t len1 = NELEMS(arr1), len2 = NELEMS(arr2);

    std::cout << "arr1: ";
    print_int_arr(arr1, len1);
    std::cout << "arr2: ";
    print_int_arr(arr2, len2);

    char arr3[len1 + len2 + 1];
    ::strcpy(arr3, arr1);
    ::strcat(arr3, arr2);
    std::cout << "arr3(arr1 + arr2): ";
    print_int_arr(arr3, len1 + len2 + 1);

    return 0;
}
