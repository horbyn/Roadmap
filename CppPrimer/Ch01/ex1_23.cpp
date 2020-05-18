#include <iostream>
#include "Sales_item.h"

int main(){
    Sales_item book, sum;
    int nr = 1;

    std::cin >> sum;
    while(std::cin >> book){
        if(compareIsbn(sum, book)){
            nr++;
        }else{
            std::cout << "Transaction of "
                    << sum.isbn() << " is "
                    << nr << std::endl;
            nr = 1;
            sum = book;
        }
    }
    std::cout << "Transaction of "
            << sum.isbn() << " is "
            << nr << std::endl;

    return 0;
}