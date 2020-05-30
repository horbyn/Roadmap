#include <iostream>

int main(){
    int ival = 0;
    int *pval = &ival;

    // before changing
    std::cout << "The value of the pointer before changing is "
            << pval << std::endl;
    pval = nullptr;
    std::cout << "The value of the pointer after changing is "
            << pval << std::endl;

    // after changing
    pval = &ival;
    std::cout << "The value to which the pointer points before changing is "
            << *pval << std::endl;
    *pval = 5;
    std::cout << "The value to which the pointer points after changing is "
            << *pval << std::endl;

    return 0;
}