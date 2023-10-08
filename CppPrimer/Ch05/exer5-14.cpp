#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string words;
    std::cout << "Please input some words: ";
    std::vector<std::string > vwords;

    while (std::cin >> words)
        vwords.emplace_back(words);

    words.clear();
    size_t nr = 1, max_nr = 1;
    std::string max_str;
    for (auto &w : vwords) {
        if (w == words)    nr++;
        else {
            if (nr > max_nr) {
                max_nr = nr;
                max_str = words;
            }
            nr = 1;
        }

        words = w;
    }
    if (nr > max_nr) {
        max_nr = nr;
        max_str = words;
    }

    if (max_nr == 1)
        std::cout << "NO REPEATED WORDS";
    else
        std::cout << max_str << " occurred " << max_nr << " times";
    std::cout << std::endl;

    return 0;
}
