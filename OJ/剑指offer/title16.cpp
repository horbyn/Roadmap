class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)    return 1.0;
        /* 负指数提示 "stack-overflow"，会使递归爆栈？
        if (n < 0) {
            long long nl = abs(n);
            return 1.0 / myPow(x, nl);
        }
        */
        // 负指数走这里，然后递归又没爆栈？想不懂，毕竟绝对值都那么大，递归层肯定都一样
        if (n == -1)    return 1 / x;

        if (n % 2)    return x * myPow(x, n - 1);	// 奇次幂
        else    return myPow(x * x, n / 2);		// 偶次幂
    }
};
