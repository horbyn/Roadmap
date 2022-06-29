#include <iostream>
int main()
{
    int sum = 0, first = 0, last = 0;

    std::cout << "Please input two integers: ";
    std::cin >> first >> last;

    if (first > last) {
        int tmp = first;
        first = last;
        last = tmp;
    }

    while (first <= last) {
        std::cout << first++ << " ";
    }

    std::cout << std::endl;
    return 0;
}
