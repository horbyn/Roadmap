class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int > dp((int)nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < (int)nums.size(); ++i)
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        int maxi = dp[0];
        for (auto v : dp)
            if (maxi < v)    maxi = v;

        return maxi;
    }
};
