#include <iostream>

int main() {
    int grade = -1;
    std::cout << "Please input your grade: ";
    std::cin >> grade;
    std::cout << (grade < 60 ? "F" :
        grade < 70 ? "D" :
        grade < 80 ? "C" :
        grade < 90 ? "B" :
        grade < 100 ? "A" :
        "A++") << std::endl;
    std::cout << std::endl;

    return 0;
}
