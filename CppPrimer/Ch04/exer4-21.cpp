#include <iostream>
#include <vector>

int main() {
    std::vector<int > v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

    for (auto &val : v)
        val = (val % 2 != 0) ? val * 2 : val * 1;

    for (auto val : v)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
