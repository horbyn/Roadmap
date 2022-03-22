/*
 * two pointers:
 * 本质仍是双指针，但这里多了一个处理删除的逻辑
 *
 * 删除思路是，删除前面和删除后面都试一次，所以需要多定义两个变量保存现场
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1;
        int ti = 0, tj = 0, cr = 1;

        while (i < j) {
            if (s[i] == s[j]) {
                ++i; --j;
                continue;
            }

            if (cr == 1) {
                ++cr;
                ti = i; tj = j;// 记录第一次不相等时的下标
                ++i;// 第一次先往后跳
            }
            else if (cr == 2) {
                ++cr;
                i = ti; j = tj;
                --j;// 第二次往前跳
            }
            else    return false;// 事不过三
        }

        return true;
    }
};
