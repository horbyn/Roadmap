#include <iostream>
#include <string>

int
main(int argc, char **argv) {
    std::string str{};
    for (size_t i = 1; argv[i]; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
