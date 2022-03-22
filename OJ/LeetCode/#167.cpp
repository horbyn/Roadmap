/*
 * two pointers:
 * 双指针一前一后，根据大小往前或往后移动
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = (int)numbers.size() - 1;

        while (i != j) {
            if (numbers[i] + numbers[j] == target)    return vector<int>{i + 1, j + 1};
            else if (numbers[i] + numbers[j] < target)    ++i;
            else if (numbers[i] + numbers[j] > target)    --j;
        }

        return {};
    }
};
