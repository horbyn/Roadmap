/*
 * 1、不管 0，遇到非零数就交换到前面
 * 2、最后才续着把 0 补至数组长度
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, nr = 0;

        for(i = 0; i < nums.size(); i++)
            if(nums[i])    nums[nr++] = nums[i];

        for(; nr < nums.size(); nr++)
            nums[nr] = 0;
    }
};