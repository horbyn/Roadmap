#include <iostream>
#include <string>
using namespace std;

int main() {
    std::cout << "read a line\n";
    std::string string_line;
    getline(std::cin, string_line);
    std::cout << "\t" << string_line << std::endl;

    std::cout << "read a word\n";
    std::string string_word;
    while (std::cin >> string_word)
        std::cout << "\t" << string_word << "\n";

    return 0;
}
