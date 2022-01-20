// 此处为状态转移方法（自底向上）；后面再补记忆化搜索方法（自顶向下）
class Solution {
public:
    int cuttingRope(int n) {
        vector<int > dp(n + 1, 0);
        dp[2] = 1;

        // i 是线段总长度; j 是每次分段的长度
        for (int i = 3; i <= n; ++i)
            for (int j = 2; j < i; ++j)
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));

        return dp[n];
    }
};
