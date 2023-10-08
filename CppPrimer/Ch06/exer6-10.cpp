#include <iostream>

void
change(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int
main(void) {
    std::cout << "Please input two integer: ";
    int first{}, second{};
    std::cin >> first >> second;
    change(&first, &second);
    std::cout << "Thest two value have changed, the first is "
        << first << ", the second is " << second << std::endl;

    return 0;
}
