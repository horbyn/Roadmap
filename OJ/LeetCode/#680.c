/*
 * 1、因为可以忽略一个字符，但是这个忽略可以是忽略左边的字符，也可以忽略右边的字符，具体忽略哪一个要尝试才知道。所以每当遇到两个不相同的字符时，根据尝试次数进行不同操作。
 * 2、另外要注意的是，这里尝试次数是 2 不是 1，因为第一次尝试过如果下面还有字符不相等，需要重新尝试。重新尝试时实际上尝试次数已经是 2 了，但根据题意来说目前仍是忽略了一个字符。之后再遇到不相等字符时，尝试次数必大于 2，这时候就没有尝试机会了。
 */

bool validPalindrome(char * s){
    int left = 0, right = strlen(s) - 1;
    // 尝试忽略字符之前，记录当前位置
    int left_tmp, right_tmp;
    // 记录尝试比较次数
    int nr = 0;

    if(right < 1)    return true;

    while(left < right){
        if(s[left] == s[right]){
            ++left; --right;
        }else{
            // 两字符不相等时有一次忽略一个字符的机会，但是
            // 忽略左边的字符还是右边的字符要尝试过才知道
            if(nr == 0){
                // 先尝试忽略左边的字符
                left_tmp = left;
                right_tmp = right;
                ++left;
                ++nr;
            }else if(nr == 1){
                // 第二次不对，就恢复第一次的现场
                left = left_tmp;
                right = right_tmp;
                --right;
                ++nr;
            }else    return false;              // 再对比不上，就没有机会了
        }
    }

    return true;
}