class Solution {
public:
    int fib(int n) {
        int dp[101] = { 0 };

        dp[0] = 0; dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= 1000000007;
        }

        return dp[n];
    }
};
