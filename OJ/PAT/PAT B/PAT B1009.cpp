/* access:
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960
 * result: AC
 * duration: 39 mins
 */

/*
 * Hello World Here I Come  =>  Come_
 *                   ^----
 * 
 * Hello World Here I       =>  Come I_
 *                 ^-
 * 
 * Hello World Here         =>  Come I Here_
 *            ^----
 *
 * Hello World              =>  Come I Here World_
 *      ^-----
 *
 * Hello                    =>  Come I Here World Hello
 * ^----
 */

#include <cstdio>

#define MAXSIZE 80

int main() {
    int sum = 0, tmp;
    int i, j = 0;
    char inp[MAXSIZE] = { 0 };
    char out[MAXSIZE] = { 0 };

    // input module
    while (1) {
        scanf("%c", &inp[sum]);
        if (inp[sum] == '\n')    break;
        sum++;
    }

    // calculate module
    tmp = sum;
    while (sum >= 0) {
        while (inp[--sum] != ' ') {
            if (!sum) {
                sum--;
                break;
            }
        }
        for (i = sum + 1; i < tmp; i++) {
            out[j++] = inp[i];
        }
        out[j++] = ' ';
        tmp = sum;
    }
    out[--j] = '\0';

    // output module
    printf("%s", out);

    return 0;
}