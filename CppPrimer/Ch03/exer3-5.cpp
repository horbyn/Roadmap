#include <iostream>
#include <string>
using namespace std;

int main() {
    std::string word, large_word;

    std::cout << "Please input some words:" << std::endl;
    while (cin >> word)
        large_word += word;
    ::getchar();

    std::cout << "The whole setence previously is: " << large_word << std::endl;

    std::cout << "\n=================================\n\n";
    std::cout << "Now please input some words again:" << std::endl;
    word.clear();
    while (std::cin >> word)
        std::cout << word << " ";
    std::cout << "The whole setence previously devided by space is: " << large_word << std::endl;

    return 0;
}
