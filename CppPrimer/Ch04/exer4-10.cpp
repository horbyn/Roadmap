#include <iostream>

int main() {
    std::cout << "Please input some integer" << std::endl;

    int tmp{};
    while ((std::cin >> tmp, tmp != 42));

    return 0;
}
