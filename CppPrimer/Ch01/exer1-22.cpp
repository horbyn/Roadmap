#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item si, sum;

    std::cin >> sum;

    while (std::cin >> si) {
        sum += si;
    }

    std::cout << sum << std::endl;

    return 0;
}
