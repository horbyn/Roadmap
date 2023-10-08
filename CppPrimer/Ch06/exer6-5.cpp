#include <iostream>

size_t
get_absolute(int val) {
    return (val < 0 ? -val : val);
}

int
main(void) {
    std::cout << "Please input a integer: ";
    int val;
    std::cin >> val;
    std::cout << "Its absolute is: " << get_absolute(val) << std::endl;

    return 0;
}
