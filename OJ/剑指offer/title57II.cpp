class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1, j = 2, sum = i + j;
        vector<vector<int > > ret;
        while (i < target) {
            if (sum < target)    ++j;
            else if (sum > target) {
                sum -= i;
                ++i;
                continue;
            } else {
                vector<int > vc;
                for (int k = i; k <= j; ++k)    vc.emplace_back(k);
                ret.emplace_back(vc);
                ++i;
                j = i + 1;
                sum = i + j;
                continue;
            }
            sum += j;
        }
        return ret;
    }
};