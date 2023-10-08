#include <iostream>
#include <string>

int main() {
    std::string words;
    std::cout << "Please input some words: ";
    std::getline(std::cin, words);

    int ff = 0, fl = 0, fi = 0;
    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i] == 'f' && (i + 1 < words.size())) {
            switch (words[i + 1]) {
            case 'f': ff++; break;
            case 'l': fl++; break;
            case 'i': fi++; break;
            default: break;
            }
            ++i;
        }
    }
    std::cout << "ff amount: " << ff
        << "\nfl amount: " << fl
        << "\nfi amount: " << fi
        << std::endl;

    return 0;
}
