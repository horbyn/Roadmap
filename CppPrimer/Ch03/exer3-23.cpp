#include <iostream>
#include <vector>

int main() {
    std::vector<int > vec;
    for (int i = 1; i <= 10; ++i)
        vec.emplace_back(i);

    for (auto it = vec.begin();
    it != vec.end(); ++it) {
        *it *= *it;
        std::cout << *it << " ";
    }
    
    std::cout << std::endl;
    return 0;
}
