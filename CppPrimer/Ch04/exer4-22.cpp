#include <iostream>
#include <string>

int main() {
    int grade;
    std::cout << "Input an integer: ";
    std::cin >> grade;

    // version 1
    std::string finalgrade = (grade < 60) ? "fail"
        : (60 <= grade && grade <= 75) ? "low pass"
        : "pass";
    std::cout << "VERSION_1: " << finalgrade << std::endl;

    // version 2
    std::cout << "VERSION_2: ";
    if (grade < 60)    std::cout << "fail";
    else if (60 <= grade && grade <= 75)    std::cout << "low pass";
    else    std::cout << "pass";
    std::cout << std::endl;

    return 0;
}
