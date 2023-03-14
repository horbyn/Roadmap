#include <iostream>
#include <vector>

int main() {
    int tmp;
    std::vector<int > vec;
    while (std::cin >> tmp)
        vec.push_back(tmp);

    // first version: sum of adjacent elements
    for (size_t i = 0; i < vec.size(); i += 2) {
        int sum = vec[i];
        if (i + 1 < vec.size())
            sum += vec[i + 1];
        std::cout << sum << " ";
    }
    
    std::cout << std::endl;

    // second version: sum of fisrt and last etc.
    size_t border = vec.size() - 1;
    for (size_t i = 0; i <= vec.size() / 2; ++i) {
        int sum = vec[i];
        if (i != border - i)
            sum += vec[border - i];
        std::cout << sum << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}
