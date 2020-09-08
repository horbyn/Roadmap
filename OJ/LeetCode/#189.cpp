class Solution {
/*
 * 1. Calculate the base index, b, to move
 * 2. Backup index 0~b(less than b)
 * 3. Index b~size(nums length) overrides index starting from 0
 * 4. Restore backup index 0~b-1
 */

public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int i, j, base, tmp[40960] = { 0 };

        if (k > size)    k %= size;
        base = size - k;

        for (i = 0; i < base; ++i)    tmp[i] = nums[i];
        for (j = 0; i < size; ++i, ++j)    nums[j] = nums[i];
        for (i = 0; j < size; ++i, ++j)    nums[j] = tmp[i];
    }
};