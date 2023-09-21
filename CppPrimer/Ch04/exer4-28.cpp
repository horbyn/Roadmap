#include <iostream>
#include <vector>

int main() {
    std::cout << "sizeof(bool)\t\t\t" << sizeof(bool)
        << "\nsizeof(signed char)\t\t" << sizeof(signed char)
        << "\nsizeof(unsigned char)\t\t" << sizeof(unsigned char)
        << "\nsizeof(signed short)\t\t" << sizeof(signed short)
        << "\nsizeof(unsigned short)\t\t" << sizeof(unsigned short)
        << "\nsizeof(float)\t\t\t" << sizeof(float)
        << "\nsizeof(signed int)\t\t" << sizeof(signed int)
        << "\nsizeof(unsigned int)\t\t" << sizeof(unsigned int)
        << "\nsizeof(signed long)\t\t" << sizeof(signed long)
        << "\nsizeof(unsigned long)\t\t" << sizeof(unsigned long)
        << "\nsizeof(double)\t\t\t" << sizeof(double)
        << "\nsizeof(long double)\t\t" << sizeof(long double)
        << "\nsizeof(long long)\t\t" << sizeof(long long)
        << "\nsizeof(unsigned long long)\t" << sizeof(unsigned long long)
        << "\nsizeof(void *)\t\t\t" << sizeof(void *)
        << std::endl;

    return 0;
}
