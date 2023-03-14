#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string tmp;
    std::vector<std::string > vec;
    while (std::cin >> tmp)
        vec.push_back(tmp);

    for (auto val : vec) {
        for (auto &ch : val)
            ch &= 0xdf; // change to upper
        std::cout << val << std::endl;
    }
    
    std::cout << std::endl;
    return 0;
}
