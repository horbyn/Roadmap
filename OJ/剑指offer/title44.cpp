/*
 * 写于前面，这是一道数学规律题，思路已记录于：
 * https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/zhao-gui-lu-cppshuang-bai-by-horbyn-85y8/
 */

class Solution {
public:
    int findNthDigit(int n) {
        long long num_base = 0, int_base = 0, pit_len = 1;
        unsigned int border = 9;

        /* 算出下标 n 对应的数字区间 */
        for (int i = 1; i <= 10; ++i) {                                 // i 表示一个数字占 i 个坑
            pit_len = i;
            long long how_many_nums = border - num_base + 1;
            long long how_many_pits = how_many_nums * pit_len;
            long long maxi_idx = int_base + how_many_pits - 1;
            if (int_base <= n && n <= maxi_idx)    break;

            num_base = border + 1;
            int_base = maxi_idx + 1;
            border = border > 999999999 ? 0x7fffffff : border * 10 + 9;
        }

        /* 计算偏移和余数 */
        long long offset = (n - int_base) / pit_len;
        long long rem = (n - int_base) % pit_len;                       // 余数
        long long num = num_base + offset;                              //对应的数字
        string str_num = to_string(num);
        return str_num[rem] - '0';                                      // 最后输出的是 char，所以要减去 '0'
    }
};