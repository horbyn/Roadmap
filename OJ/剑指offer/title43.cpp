class Solution {
public:
    int countDigitOne(int n) {
        int high = n, low = 0, num = 1, cur = 0, sum = 0;
        while (high != 0 || cur != 0) {
            cur = high % 10;
            high /= 10;

            if (cur < 1)    sum += high * num;
            else if (cur == 1)    sum += high * num + low + 1;
            else    sum += high * num + num;

            low = cur * num + low;
            if (high > 0)    num *= 10;
        }
        return sum;
    }
};
