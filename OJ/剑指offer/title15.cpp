class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cr = 0;
        while (n) {
            if (n % 2)    cr++;
            n /= 2;
        }
        return cr;
    }
};
