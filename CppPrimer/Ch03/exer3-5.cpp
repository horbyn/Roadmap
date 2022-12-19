#include <iostream>
#include <string>

int main() {
    std::string word, large_word;

    std::cout << "Please input some words:" << std::endl;
    while (std::cin >> word) {
        large_word += word;
        if (std::cin.get() == '\n')    break;
    }

    std::cout << "The whole setence previously is: " << large_word << std::endl;

    std::cout << "\n=================================\n\n";
    std::cout << "Now please input some words again:" << std::endl;
    large_word.clear();
    while (std::cin >> word) {
        large_word += word + " ";
        if (std::cin.get() == '\n')    break;
    }
    std::cout << "The whole setence previously devided by space is: " << large_word << std::endl;

    return 0;
}
