/*
 * 思路：每遍历到空格，就记录其后有效字符串长度
 * 1、每遍历到空格，先检查后面的字符是否有效（非字符串末尾，非空格），若是重置长度
 * 2、每遍历到非空格，直接字符串长度自增
 */

int lengthOfLastWord(char * s){
    int i = 0;
    int all_space = 0;                              // 记录空格个数
    int length = 0;

    while(*(s + i)){
        if(*(s + i) == ' '){                        // 当前字符为空格
            if(*(s + i + 1) && *(s + i + 1) != ' ') // 只有下个字符有效才重置长度
                length = 0;
            all_space++;
        }else    length++;                          // 当前字符非空格
        i++;
    }

    if(all_space == strlen(s))    return 0;         // 全空格字符串无效
    else    return length;
}