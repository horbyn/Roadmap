/*
 * 思路就是不断检查后面的字符串（如果有），与第一个字符串各个字符是否相同
 * 1、外循环 while() 枚举每个字符串
 * 2、内循环 while() 枚举字符串中每个字符
 * 3、如果当前内循环所枚举的字符是所有字符串都拥有时，就将该字符加入待返回的字符串
 */

char * longestCommonPrefix(char ** strs, int strsSize){
    /* i 枚举字串；
     * j 枚举字串中的字符；
     * k 也枚举字串，但在比较字串中记录当前字串位置；
     * nr 当将字符追加到前缀时，记录字符位置
     */
    int i = 0, j = 0, k, nr;
    char ret[1024] = "";                        // 定义空字符串
    char *pret = ret;
    char ch;

    // 特殊情况
    if(!strsSize)    return pret;               // []的情况返回""
    else if(strsSize == 1)    return *(strs);   // 只有一个串的情况就返回该串

    while(*(*(strs + i) + j)){                  // 检索第一个字串直至末尾
        ch = *(*(strs + i) + j);

        k = 1;
        // 检索其余串的每个字符是否都与第一个串的每个字符相等
        while(*(*(strs + i + k) + j) == ch){
            k++;                                // 相等就一直检索下去
            if(k == strsSize)    break;         // 检查到最后一个都相同就退出
        }// 退出循环时可能所有串有共同前缀，也有可能无共同前缀，通过 k 来区分两种情况

        if(k != strsSize)    break;             // 未检查完所有字串，即当前字符不能被追加至前缀
        else{
            // 所有字串中都存在当前这个字符，则将该字符追加至前缀
            j++;
            nr = 0;
            if(*(ret) == '\0'){
                // 如果前缀字串是空，直接插入
                *(ret) = ch;
                *(ret + 1) = '\0';
            }else{
                // 如果前缀字串非空，在串尾插入
                while(*(ret + nr))    nr++;
                *(ret + nr++) = ch;
                *(ret + nr) = '\0';
            }
        }
    }

    return pret;
}