class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int > dp(n + 1, 0);
        dp[1] = 1;

        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; ++i) {
            // 题目明确 "只包含质因子 2、3、5" 意味着 14 这种不算丑数
            // 因此倍数要算 dp[i] 的倍数，而不能算下标 i 的倍数
            dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
            if (dp[i] == dp[p2] * 2)    p2++;
            if (dp[i] == dp[p3] * 3)    p3++;
            if (dp[i] == dp[p5] * 5)    p5++;
        }

        return dp[n];
    }
};
