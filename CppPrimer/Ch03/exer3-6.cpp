#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string val;
    std::cout << "please input a sentence: " << std::endl;

    std::getline(std::cin, val);
    for (auto &v: val)
        v = 'X';
    
    std::cout << "your sentance after some handling is: " << val << std::endl;

    return 0;
}
