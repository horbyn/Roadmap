#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string > text;
    std::string tmp;
    while (std::cin >> tmp)
        text.emplace_back(tmp);

    for (auto it = text.begin();
    it != text.end() && !it->empty(); ++it) {
        for (auto &ch : *it)
            ch &= 0xdf;
        std::cout << *it << std::endl;
    }
    
    return 0;
}
