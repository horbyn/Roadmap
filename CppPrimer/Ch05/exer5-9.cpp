#include <iostream>
#include <string>

int main() {
    std::string words;
    std::cout << "Please input some words: ";
    std::getline(std::cin, words);

    int nr = 0;
    for (auto ch : words)
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' || ch == 'A' ||
            ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            nr++;
    std::cout << "Vowel amount: " << nr << std::endl;

    return 0;
}
