#include <iostream>
#include <vector>

int main() {
    int tmp;
    std::vector<int > vec;
    while (std::cin >> tmp)
        vec.push_back(tmp);

    // first version: sum of adjacent elements
    for (auto it = vec.begin(); it < vec.end(); it += 2) {
        int sum = *it;
        if (it + 1 != vec.end())
            sum += *(it + 1);
        std::cout << sum << " ";
    }
    
    std::cout << std::endl;

    // second version: sum of fisrt and last etc.
    for (auto it1 = vec.begin(), it2 = vec.end() - 1;
    it1 <= it2; ++it1, --it2) {
        int sum = *it1;
        if (it1 != it2)    sum += *it2;
        std::cout << sum << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}
