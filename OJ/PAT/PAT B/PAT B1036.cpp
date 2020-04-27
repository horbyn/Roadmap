/* access:
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805285812551680
 * result: PA 11/15
 * duration: 23 mins
 */

#include <cstdio>

int main() {
    int inp;
    char ch;
    int i, j;

    // input module
    scanf("%d %c", &inp, &ch);

    // calculate module
    

    // output module
    for (i = 0; i < inp / 2; i++) {
        for (j = 0; j < inp; j++) {
            if (i == 0 || i == inp / 2 - 1 || j == 0 || j == inp - 1) {
                printf("%c", ch);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

/*
Fst submit:
Case	Result	        Run Time	Memory
0       Accepted        4 ms	    228 KB
1       Wrong Answer    2 ms	    296 KB
2       Wrong Answer    3 ms	    568 KB
3       Accepted        3 ms	    500 KB
4       Accepted        3 ms	    256 KB
*/