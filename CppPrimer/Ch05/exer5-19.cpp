#include <iostream>
#include <string>

int main() {
    std::string s1{}, s2{};

    do {
        std::cout << "Please input two string:\n";
        std::cin >> s1 >> s2;

        if (!s1.empty() && !s2.empty()) {
            std::cout << "the less is: "
                << (s1.size() < s2.size() ? s1 : s2) << std::endl;
            s1.clear();
            s2.clear();
        }
    } while (std::cin);

    return 0;
}
