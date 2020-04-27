/* access:
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805285812551680
 * result: AC
 * duration: 23 mins + 5 mins
 */

#include <cstdio>
#include <cmath>

int main() {
    double inp;
    int line, col;
    char ch;
    int i, j;

    // input module
    scanf("%lf %c", &inp, &ch);

    // calculate module
    line = round(inp / 2);
    col = (int)inp;

    // output module
    for (i = 0; i < line; i++) {
        for (j = 0; j < col; j++) {
            if (i == 0 || i == line - 1 || j == 0 || j == col - 1) {
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