#include <iostream>
#include <string>

int main() {
    std::string val, out;
    std::cout << "please input a sentence: " << std::endl;

    std::getline(std::cin, val);
    for (auto v: val) {
        if (('A' <= v && v <= 'Z') || ('a' <= v && v <= 'z') || v == ' ' || v == '\t')
            out += v;
    }
    
    std::cout << "your sentance after some handling is: " << out << std::endl;

    return 0;
}
