// 写在前面：二分比较麻烦的是细节（比如边界是 < 还是 ≤ 之类），我的办法是先写然后根据题意和例子完善细节
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = (int)nums.size();

        int left = 0, right = size - 1, mid;
        // 等于是为了给 size = 1 的数组作出处理
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            // 序号与元素相等，说明缺失元素在后面
            if (mid == nums[mid])    left = mid + 1;
            // 序号比元素小，不一定说明就是这个位置出了问题，有可能是前面某个位置缺失导致
            // 所以仍需往前走，直至找到 left > right
            else if (mid < nums[mid])    right = mid - 1;
        }

        return left;
    }
};