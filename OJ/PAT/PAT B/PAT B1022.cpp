/* access:
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805299301433344
 * result: PA 16/20
 * duration: 35 mins
 */

/*
 *    72       9      1       0
 * 8/579    8/72    8/9     8/1
 *   56       72      8       0
 *   ---      --      -       -
 *    19       0      1       1       =>    1103
 *    16
 *   ---
 *     3
 */

#include <cstdio>
#include <cmath>

#pragma warning(disable: 4996)

static int buf_ptr = 0;
static int buf[32] = { 0 };

int trans_dec2other(int, int);

int main() {
    int a, b, sum, d;
    int i, j;

    // input module
    scanf("%d%d%d", &a, &b, &d);

    // calculate module
    sum = trans_dec2other(a + b, d);

    // output module
    printf("%d", sum);

    return 0;
}

int trans_dec2other(int ori, int dec) {
    int quotient;
    int exponent = 0;
    int sum = 0;

    // calculate
    while (ori) {
        quotient = ori % dec;
        ori /= dec;
        sum += quotient * pow(10, exponent++);
    }
    
    return sum;
}

/*
Fst submit:
Case	Result	        Run Time	Memory
0       Accepted        3 ms	    384 KB
1       Accepted        3 ms	    256 KB
2       Wrong Answer    3 ms	    256 KB
3       Accepted        3 ms	    228 KB
4       Wrong Answer    3 ms	    384 KB
5       Accepted        3 ms	    468 KB
*/