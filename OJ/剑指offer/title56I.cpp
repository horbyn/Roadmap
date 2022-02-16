class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0)    return {};

        // 所有数异或
        int mask = 0;
        for (auto v : nums)    mask = mask ^ v;

        // 得到依据 bit 位，取最低的那位
        int idx = 0;
        for (; !(mask & 1); ++idx)    mask >>= 1;
        int pivot = 1 << idx;

        // 分组异或
        int a1 = 0, a2 = 0;
        for (auto v : nums) {
            if (v & pivot)    a1 = a1 ^ v;
            else    a2 = a2 ^ v;
        }

        return vector<int > {a1, a2};
    }
};
