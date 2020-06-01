/*
 * 思路：每读取一个不同的字符，就记录从该字符开始后面还有几个到下一个不同的字符（需要注意的是这个记录要转化为ascii字符——方法就是逆序取余法）
 * 1、常规地遍历每个字符，若是与之前记录的字符相同直接长度记录自增
 * 2、若不是就保存该字符与其长度，长度涉及整数转字符串
 * 3、最后退出循环时按while()条件最后一个字符是不被保存的，需要额外保存一次
 */

char* compressString(char* s){
    char ret[60000] = "";
    char *pret = ret;
    // 整数转化字符中途保存数据的数组
    char i2c[6] = "";

    // j 判断有几个不同字符; nr 记录ret 长度
    int i = 0, j = 0, nr = 0;
    // trans_nr 记录整数最高幂方次数, quotient 记录商, remainder 记录余数
    int trans_nr = 0, quotient = 0, remainder = 0;
    char ch = s[0];

    while(s[i]){
        if(ch == s[i]){
            // 如果遍历的字符与前面记录的字符相等就一直继续检查
            j++;
        }else{
            // 如果不相等就保存当前记录的字符信息，然后重置为另一个字符
            ret[nr++] = ch;
            quotient = j;                                   // 初始商即字符个数
            while(quotient){
                remainder = quotient % 10;                  // 余数和最终转化出来的字符有关
                i2c[trans_nr++] = '0' + (char)remainder;    // 记录余数
                quotient /= 10;
            }
            while(trans_nr){
                ret[nr++] = i2c[--trans_nr];                // 逆序取出余数即整数对应的字符串
            }
            j = 1;
            ch = s[i];
        }
        ++i;
    }
    // 检索到末尾会退出循环，所以检索到最后一类重复字符要额外添加
    ret[nr++] = ch;
    quotient = j;
    while(quotient){
        remainder = quotient % 10;
        i2c[trans_nr++] = '0' + (char)remainder;
        quotient /= 10;
    }
    while(trans_nr){
        ret[nr++] = i2c[--trans_nr];
    }
    ret[nr] = '\0';

    if(strlen(s) <= nr)    return s;
    else    return pret;
}