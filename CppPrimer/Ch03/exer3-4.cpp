#include <iostream>
#include <string>
using namespace std;

int main() {
    std::cout << "judge equality\n";
    std::string string_val1, string_val2;
    std::cout << "please input the first string: ";
    getline(std::cin, string_val1);
    std::cout << "please input the second string: ";
    getline(std::cin, string_val2);
    if (string_val1 == string_val2)
        std::cout << "the two strings are equal!" << std::endl;
    else {
        std::cout << "the two are not equal! ";
        if (string_val1 > string_val2)
            std::cout << "and the first is larger" << std::endl;
        else
            std::cout << "and the second is larger" << std::endl;
    }

    std::cout << "\n======================\n\n";


    std::cout << "please input the first string again: ";
    getline(std::cin, string_val1);
    std::cout << "please input the second string again: ";
    getline(std::cin, string_val2);
    if (string_val1.size() == string_val2.size())
        std::cout << "the two strings have same size!" << std::endl;
    else {
        std::cout << "the two have not same size! ";
        if (string_val1.size() > string_val2.size())
            std::cout << "and the first is longer" << std::endl;
        else
            std::cout << "and the second is longer" << std::endl;
    }

    return 0;
}
