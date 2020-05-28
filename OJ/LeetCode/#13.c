/*
 * 【思路】：每读取一个罗马数字，也需要同时读取其下一个罗马数字，比较它们大小：
 *             若当前数值大于等于下一数值，直接将当前数值添加至累加和；
 *             否则若小于下一数值，需要求下一数值和当前数值之差，将差添加至累加和
 * 1、综上所述，由于读取当前值时需要同时读取下一数值，所以先将字符串转换为整型数组
 * 2、读取元素开始比较当前数值和下一数值
 */

int romanToInt(char * s){
    int i = 0;
    int size = strlen(s);
    int sum = 0, tmp;               // 记录“和”和“中间值”
    int cur;                        // 字符串转整数时需要用作记录
    int n[1024];                    // 字符串对应整数数组

    while (i < size) {
        // 字符串转换整数
        switch (s[i]) {
            case 'I':    cur = 1; break;
            case 'V':    cur = 5; break;
            case 'X':    cur = 10; break;
            case 'L':    cur = 50; break;
            case 'C':    cur = 100; break;
            case 'D':    cur = 500; break;
            case 'M':    cur = 1000; break;
            default:    break;
        }
        n[i] = cur;
        i++;
    }

    i = 0;
    while (i < size) {
        // 由于每读取一个数值，需要同时比较下一数值，
        // 为防止当前数值为最后一个元素时越界，加入此判断
        if (i + 1 == size){
            sum += n[i];
            break;
        }

        // 由题干得当前数值小于下一数值时，要求得下一数值和当前数值之差
        // 最后才是将该差添加至累加和
        if (n[i] < n[i + 1]) {
            tmp = n[i + 1] - n[i];
            sum += tmp;
            i++;
        }
        else    sum += n[i];        // 若当前数值大于等于下一数值，直接累加
        i++;
    }

    return sum;
}