/*
 * 思路：直接不断头和尾交换直至遍历到串中间
 */

void reverseString(char* s, int sSize){
    int i = 0, swap = 0;

    if(sSize < 2)    return;

    while(i < sSize / 2){
        swap = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = swap;
        i++;
    }
}