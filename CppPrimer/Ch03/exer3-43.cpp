#include <iostream>
#include <vector>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

constexpr size_t rowCnt = 3, colCnt = 4;
static int ia[rowCnt][colCnt]{};

void init_arr() {
    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != colCnt; ++j) {
            ia[i][j] = i * colCnt + j;
        }
    }
}

int main() {
    init_arr();

    // version 1:
    std::cout << "version 1:" << std::endl;
    for (auto &row : ia) {
        for (auto col : row)
            std::cout << col << " ";
        std::cout << std::endl;
    }
    
    // version 2:
    std::cout << "\nversion 2:" << std::endl;
    for (size_t i = 0; i < rowCnt; ++i) {
        for (size_t j = 0; j < colCnt; ++j)
            std::cout << ia[i][j] << " ";
        std::cout << std::endl;
    }
    
    // version 3:
    std::cout << "\nversion 3:" << std::endl;
    int (*p)[colCnt] = ia;
    for (size_t i = 0; i < rowCnt; ++i) {
        for (size_t j = 0; j < colCnt; ++j)
            std::cout << p[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
