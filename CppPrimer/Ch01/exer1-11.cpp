#include <iostream>
int main()
{
    int sum = 0, first = 0, last = 0;

    std::cout << "Please input two integers: ";
    std::cin >> first >> last;

    while (first <= last) {
        std::cout << first++ << " ";
    }

    return 0;
}
