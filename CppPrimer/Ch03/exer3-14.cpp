#include <iostream>
#include <vector>

int main() {
    int tmp;
    std::vector<int > vec;
    while (std::cin >> tmp)
        vec.push_back(tmp);

    for (auto val : vec)
        std::cout << val << " ";
    
    std::cout << std::endl;
    return 0;
}
