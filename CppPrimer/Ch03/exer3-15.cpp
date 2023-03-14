#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string tmp;
    std::vector<std::string > vec;
    while (std::cin >> tmp)
        vec.push_back(tmp);

    for (auto val : vec)
        std::cout << val << " ";
    
    std::cout << std::endl;
    return 0;
}
