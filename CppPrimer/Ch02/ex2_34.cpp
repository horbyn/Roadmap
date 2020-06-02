#include <iostream>

int main(){
    // i is int& refering to int 
    int i = 0, &r = i;
    // a is int
    auto a = r;
    std::cout << "Before assignment, a = " << a << std::endl;
    a = 42;
    std::cout << "After assignment, a = " << a << std::endl;

    // ci is const int, cr is const int&
    const int ci = i, &cr = ci;
    // b is int, because auto ignores top-level const
    auto b = ci;
    std::cout << "Before assignment, b = " << b << std::endl;
    b = 42;
    std::cout << "After assignment, b = " << b << std::endl;

    // c is int, because ci refers to const int object that auto will ignore
    auto c = cr;
    std::cout << "Before assignment, c = " << c << std::endl;
    c = 42;
    std::cout << "After assignment, c = " << c << std::endl;

    // d is int *
    auto d = &i;
    std::cout << "Before assignment, d = " << d << std::endl;
    d = 42;
    std::cout << "After assignment, d = " << d << std::endl;

    // e is const int *
    auto e = &ci;
    std::cout << "Before assignment, e = " << e << std::endl;
    e = 42;
    std::cout << "After assignment, e = " << e << std::endl;

    // g is const int&
    auto &g = ci;
    std::cout << "Before assignment, g = " << g << std::endl;
    g = 42;
    std::cout << "After assignment, g = " << g << std::endl;

    return 0;
}