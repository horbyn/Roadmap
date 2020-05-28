#include <stdio.h>

int equal(int, int);

int main()
{
    int x, y;
    int res;

    printf("Input two numbers to test: ");
    scanf("%d%d", &x, &y);

    res = equal(x, y);
    printf("%d\n", res);

    return 0;
}

int equal(int x, int y){
    int i = 0;
    int x_tmp = x, y_tmp = y;
    int flag = 0;

    while(i < 8){
        // 1 << i 左移相当于乘 2 的幂，即求 2 的0、1、2...7 次幂
        // 任一数值和 2 次幂进行与运算，即求出该数的每一个比特位
        // 比如 1110 0010，第 0 位由“与 1”求得，第 1 位由“与 2”求得..
        x_tmp &= (1 << i);
        y_tmp &= (1 << i);
        // 异或两个数对应的位，相同求得 0
        if(x_tmp ^ y_tmp)    break;
        else    i++;

        // 每移位一次比较完后需要重新赋值
        x_tmp = x;
        y_tmp = y;
    }
    // 如果全部位都通过检查，说明全部位都相等
    if(i == 8)    flag = 1;

    return flag;
}