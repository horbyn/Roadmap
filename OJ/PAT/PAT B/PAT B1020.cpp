/* access:
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805301562163200
 * result: AC
 * duration: 54 mins
 */

 /*
  * 1. 计算单价
  * 2. 按单价排序
  * 3. 检索最高单价的库存
  *     3-1. 库存足够: 计算库存还剩多少; 计算拿走的占总库存多少; 根据比例算收益
  *     3-2. 库存不足够: 计算库存差多少; 计算收益
  */

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXSIZE 1000

typedef struct mooncake {
    double price;
    double stock;
    double unit;
}mooncake_t;

void read_input(void);
double calculate(void);
mooncake_t mooncake[MAXSIZE] = { 0 };
double kind, demand;

int main() {
    double profit = 0;

    // input module
    read_input();

    // calculate module
    profit = calculate();

    // output module
    printf("%0.2lf", profit);

    return 0;
}

void read_input() {
    int i;

    scanf("%lf%lf", &kind, &demand);
    for (i = 0; i < kind; i++) {
        scanf("%lf", &mooncake[i].stock);
    }
    for (i = 0; i < kind; i++) {
        scanf("%lf", &mooncake[i].price);
    }
}

bool cmp(mooncake_t a, mooncake_t b) {
    return a.unit > b.unit;
}

double calculate() {
    int i;
    double proportion, profit = 0;

    // 1. calculate unit price
    for (i = 0; i < kind; i++) {
        mooncake[i].unit = mooncake[i].price / mooncake[i].stock;
    }
    // 2. sort by unit price
    sort(mooncake, mooncake + (int)kind, cmp);
    // 3. calculate profit according whether the highest unit price has stock
    i = 0;
    while (demand) {
        if (i >= kind)    break;
        if (mooncake[i].stock >= demand) {              // enough
            proportion = demand / mooncake[i].stock;
            mooncake[i].stock -= demand;
            demand = 0;
            profit += mooncake[i].price * proportion;
        }
        else {                                          // not enough
            demand -= mooncake[i].stock;
            mooncake[i].stock = 0;
            profit += mooncake[i].price;
        }
        i++;
    }

    return profit;
}