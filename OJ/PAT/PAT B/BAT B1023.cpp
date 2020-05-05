/* access:
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805298269634560
 * result: AC
 * duration: 37 mins
 */

 /*
  * 1. sort
  * 2. change the first number if it's zero
  */

#include <cstdio>

#define MAXSIZE 50

int main() {
    int arr[MAXSIZE] = { 0 };
    int i, j, sum = 0, inp, tmp;
    bool fchange = false;

    // input module
    for (i = 0; i < 10; i++) {
        scanf("%d", &inp);
        for (j = sum; j < sum + inp; j++) {
            arr[j] = i;
        }
        sum += inp;
    }

    // calculate module
    i = 0;
    while (!arr[i]) {
        i++;
        fchange = true;
    }
    if (fchange) {
        tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
    }

    // output module
    for (i = 0; i < sum; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}