
#include <iostream>
#include <vector>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return a / b; }

int main(void) {
    std::vector<int (*)(int, int) > v{};

    v.emplace_back(add);
    v.emplace_back(sub);
    v.emplace_back(mul);
    v.emplace_back(divi);

    std::cout
        << "+: " << v[0](1, 1) << std::endl
        << "-: " << v[1](1, 2) << std::endl
        << "*: " << v[2](1, 3) << std::endl
        << "/: " << v[3](1, 4) << std::endl;

    return 0;
}
