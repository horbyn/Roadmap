// 直接 dp 接个模除不可以
class Solution {
public:
    int cuttingRope(int n) {
        // n <= 3
        if (n < 4)    return n - 1;

        // n > 3
        vector<long long > dp(n + 1, 1);
        int mod = 1000000007;
        if (n > 3) {
            // 能分为 3 的整数倍
            int cr = n / 3, last = n % 3;
            for (int i = 1; i < cr; ++i)    dp[n] = dp[n] * 3 % mod;
            // 最后一段若不满 3 只有三种情况：0、1、2
            if (last == 0) {
                dp[n] *= 3;
            }
            else if (last == 1) {
                // 若最后一段为 1，将前面的 3 + 1 换成 2 + 2，因为后者乘积更大
                dp[n] *= (2 * 2);
            }
            else {
                // 若最后一段为 2，因为 2 > 1 + 1 因此不拆即直接乘 2
                dp[n] *= (3 * 2);
            }
            dp[n] %= mod;
        }

        return dp[n];
    }
};
