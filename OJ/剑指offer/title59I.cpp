// 此处先暴力解， 但主站同一题 #239 不优化不可能 A，先挖坑
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = (int)nums.size();
        if (size == 0)    return vector<int > {};

        int resize = size - k + 1;
        vector<int > dp(resize, 0);
        // 找出前 k 个数最大值
        int maxi = nums[0];
        for (int i = 0; i < k; ++i)
            if (maxi < nums[i])    maxi = nums[i];
        dp[0] = maxi;

        for (int i = 1; i < resize; ++i) {
            // 先取滑动窗口由于移走而丢弃的数
            int del = nums[i - 1];
            if (del >= maxi) {
                // case 1：移走那个数是上一次的最大值，那就重新排序
                maxi = nums[i];
                for (int j = i; j < i + k; ++j)
                    if (maxi < nums[j])    maxi = nums[j];
                dp[i] = maxi;
            } else    dp[i] = max(dp[i - 1], nums[i + k - 1]);// case 2：移走的数非最大值，直接按 dp() 的方法取值
        }

        return dp;
    }
};
