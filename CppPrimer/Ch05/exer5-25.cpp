#include <iostream>
#include <stdexcept>

int main() {

    int i1{}, i2{};

    while (1) {
        try {

            std::cout << "Please input two integer: ";
            std::cin >> i1 >> i2;
            if (i2 == 0)    throw std::runtime_error("divisor cannot be zero");
            std::cout << "The quotient is: " << (i1 / i2) << std::endl;

            break;

        } catch (const std::runtime_error &re) {
            std::cout << re.what() << std::endl;

            std::cout << "If try again(y/n): ";
            char ch;
            std::cin >> ch;
            if (ch == 'y')    continue;
            else    break;
        }
    }

    return 0;
}
