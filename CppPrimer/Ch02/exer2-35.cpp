#include <iostream>
#include <typeinfo>

int main() {
    const int i = 42;
    auto j = i;                     // int
    const auto &k = i;              // const int &
    auto *p = &i;                   // int *
    const auto j2 = i, &k2 = i;     // const int, const int &

    std::cout << "i 类型: " << typeid(i).name() << std::endl;
    std::cout << "j 类型: " << typeid(j).name() << std::endl;
    std::cout << "k 类型: " << typeid(k).name() << std::endl;
    std::cout << "p 类型: " << typeid(p).name() << std::endl;
    std::cout << "j2 类型: " << typeid(j2).name() << std::endl;
    std::cout << "k2 类型: " << typeid(k2).name() << std::endl;

    return 0;
}
