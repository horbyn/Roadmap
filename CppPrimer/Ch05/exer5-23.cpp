#include <iostream>

int main() {

    std::cout << "Please input two integer: ";

    int i1{}, i2{};
    std::cin >> i1 >> i2;

    std::cout << "The quotient is: " << (i1 / i2) << std::endl;

    return 0;
}
