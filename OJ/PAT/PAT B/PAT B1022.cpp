/* access:
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805299301433344
 * result: PA 18/20
 * duration: 35 mins + 53 mins + 16 mins
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

#define MAXSIZE 32

static int buf_ptr = 0;
static int buf[MAXSIZE] = { 0 };

void trans_dec2other(int, int);

int main() {
    int a, b, d;
    int i, j;

    // input module
    scanf("%d%d%d", &a, &b, &d);

    // calculate module
    trans_dec2other(a + b, d);

    // output module
    while (buf_ptr) {
        printf("%d", buf[--buf_ptr]);
    }

    return 0;
}

void trans_dec2other(int ori, int dec) {
    int quotient;

    // calculate
    while (ori) {
        quotient = ori % dec;
        ori /= dec;
        buf[buf_ptr++] = quotient;
    }
}

/*
Fst submit:
Case	Result	        Run Time	Memory
0       Accepted        2 ms	    352 KB
1       Accepted        2 ms	    360 KB
2       Accepted        2 ms	    296 KB
3       Wrong Answer    3 ms	    296 KB
4       Accepted        3 ms	    224 KB
5       Accepted        2 ms	    384 KB
*/