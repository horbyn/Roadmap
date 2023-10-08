#include <iostream>

int main() {
    int grade = -1;
    std::cout << "Please input your grade: ";
    std::cin >> grade;
    if (grade < 60)    std::cout << "F";
    else if (grade < 70)    std::cout << "D";
    else if (grade < 80)    std::cout << "C";
    else if (grade < 90)    std::cout << "B";
    else if (grade < 100)    std::cout << "A";
    else    std::cout << "A++";
    std::cout << std::endl;

    return 0;
}
