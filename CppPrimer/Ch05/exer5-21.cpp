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
            if (str.size() > 1 && 'A' <= str[0] && str[0] <= 'Z') {

                std::cout << "the string(" << str << ") has happened "
                    << repeated << " times" << std::endl;
                break;
            } else    continue;
        }
    }
    if (repeated == 1)
        std::cout << "no repeated strings" << std::endl;

    return 0;
}
