#include <iostream>

int main(){
    int sum = 0, val = 0;

    for(; std::cin >> val;){
        sum += val;
    }
    std::cout << "The sum of these number you input is "
            << sum << std::endl;

    return 0;    
}