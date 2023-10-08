#include <iostream>
#include <vector>

int main() {
    std::vector<int > v1{ 0, 1, 1, 2 }, v2{ 0, 1, 1, 2, 3, 5, 8 };

    bool flag = true;
    if (v1.size() == v2.size()) {
        if (v1 == v2)    flag = true;
    } else {
        for (size_t i = 0; i < v1.size() && i < v2.size(); ++i)
            if (v1[i] != v2[i]) {
                flag = false;
                break;
            }
    }

    std::cout << (flag ? "true" : "false") << std::endl;

    return 0;
}
