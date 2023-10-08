#include <iostream>
#include <stdexcept>

int main() {

    std::cout << "Please input two integer: ";
    int i1{}, i2{};

    std::cin >> i1 >> i2;
    if (i2 == 0)    throw std::runtime_error("divisor cannot be zero");
    std::cout << "The quotient is: " << (i1 / i2) << std::endl;

    return 0;
}
