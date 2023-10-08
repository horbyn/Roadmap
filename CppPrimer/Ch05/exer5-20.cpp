#include <iostream>
#include <string>

int main() {
    std::string str{}, pre{};
    size_t repeated = 1;

    while (std::cin >> str) {
        if (str == pre)    repeated++;
        else {
            repeated = 1;
            pre = str;
        }

        if (repeated == 2) {
            std::cout << "the string(" << str << ") has happened "
                << repeated << " times" << std::endl;
            break;
        }
    }
    if (repeated == 1)
        std::cout << "no repeated strings" << std::endl;

    return 0;
}
