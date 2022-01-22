class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0)    return {};
        int i = 0, j = size - 1;

        while (i != j) {
            while (i != j && !(nums[j] & 1))    --j;
            while (i != j && nums[i] & 1)    ++i;
            if (nums[i] != nums[j])    swap(nums[i], nums[j]);
        }

        return nums;
    }
};
