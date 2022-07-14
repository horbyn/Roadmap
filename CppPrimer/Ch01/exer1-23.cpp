#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item si1, si2;
    int cr = 1;

    std::cin >> si1;

    while (std::cin >> si2) {
        if (si1.isbn() == si2.isbn())    cr++;
        else {
            std::cout << si1.isbn() << " occurs " << cr << std::endl;
            si1 = si2;
            cr = 1;
        }
    }
    std::cout << si1.isbn() << " occurs " << cr << std::endl;

    return 0;
}
