#include <iostream>

int main() {
    int ori = 10;
    int *po = &ori;

    std::cout << "the origin pointer: " << po << std::endl;

    int chg = 20;
    po = &chg;
    std::cout << "the changed pointer: " << po << std::endl;

    *po = 30;
    std::cout << "the object the pointer pointed to: " << *po
        << std::endl;

    return 0;
}
