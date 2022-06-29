#include <iostream>
int main()
{
    int sum = 0, val = 0;
    
    std::cout << "Please enter some numbers, ctrl + d to quit"
              << std::endl;

    while (std::cin >> val)
        sum += val;
    
    std::cout << "Sum of these numbers is "
              << sum << std::endl;

    return 0;
}
