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
    
    std::cout << "\narray:" << std::endl;
    typedef int (* ptr_arr_t)[colCnt];

    ptr_arr_t p = ia;
    for (size_t i = 0; i < rowCnt; ++i) {
        for (size_t j = 0; j < colCnt; ++j)
            std::cout << p[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
