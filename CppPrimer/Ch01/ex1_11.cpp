#include <iostream>

int main(){
    int val1, val2;
    int start, end;

    std::cout << "Please input two number in order to print each number in the range specified by these two integers: ";
    std::cin >> val1 >> val2;

    if(val1 <= val2){
        start = val1;
        end = val2;
    }else{
        start = val2;
        end = val1;
    }

    while(start <= end){
        std::cout << start++ << " ";
    }
    std::cout << std::endl;

    return 0;    
}