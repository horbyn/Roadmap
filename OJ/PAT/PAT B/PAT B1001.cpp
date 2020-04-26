/* access:
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528
 * completation: Apr 26th, 2020
 * result: AC 15/15
 */

/*
 * 0. 3
 * (3 * 3 + 1) / 2 = 5
 *
 * 1. 5
 * (3 * 5 + 1) / 2 = 8
 *
 * 2. 8
 * 8 / 2 = 4
 *
 * 3. 4
 * 4 / 2 = 2
 *
 * 5. 2
 * 2 / 2 = 1
 *
 */

#include <cstdio>

int main() {
    int inp;
    int i;

    scanf("%d", &inp);
    for (i = 0; inp != 1; i++) {
        if (inp % 2) {
            inp = (3 * inp + 1) / 2;
        }
        else {
            inp /= 2;
        }
    }

    printf("%d", i);

    return 0;
}