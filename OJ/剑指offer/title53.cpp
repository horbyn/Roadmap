// 记得最早刷 PAT 的时候，备考时参考的 ⌈算法笔记⌋ 二分法实现 lower_bound() 和 upper_bound()
// v1: 自己二分法实现，耗时 4ms
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = (int)nums.size();
        if (size == 0)    return 0;

        // 找第一个大于等于 target 的下标
        int left = 0, right = size, mid;                // 上界是 n
        int start = 0, end = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (target <= nums[mid])    right = mid;
            else    left = mid + 1;
        }
        // 第一个等于 target 都没找到，那就是没有
        if (left >= size || nums[left] != target)    return 0;

        // 找第一个大于 target 的下标
        start = left;
        left = 0; right = size;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (target < nums[mid])    right = mid;
            else    left = mid + 1;
        }
        end = left;
        return end - start;
    }
};

// v2: 直接用 stl，耗时 4ms（可以发现耗时一样）
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = (int)nums.size();
        if (size == 0)    return 0;

        vector<int >::iterator start = lower_bound(nums.begin(), nums.end(), target);
        if (start == nums.end() || *start != target)    return 0;

        vector<int >::iterator end = upper_bound(nums.begin(), nums.end(), target);
        return end - start;
    }
};