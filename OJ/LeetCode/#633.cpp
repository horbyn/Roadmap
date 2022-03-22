/*
 * two pointers:
 * 本质是一前一后双指针，根据大小产生往前往后的移动
 *
 * [注] 但这里有个溢出的案列，所以要转 long long
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0, j = (int)sqrt(c) + 1;

        while (i <= j) {
            long long tmp = (long long)i * i + (long long)j * j;
            if (c == tmp)    return true;
            else if (c < tmp)    --j;
            else    ++i;
        }

        return false;
    }
};
