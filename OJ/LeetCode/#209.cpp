// version 1: 头指针每次自增 1，因此时间复杂度较高
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = (int)nums.size();
        int min = 0x7fffffff, tmp = 0;
        long long sum = 0;

        for (int i = 0; i < size; ++i) {
            int j = i;
            
            while (j < size) {
                sum += nums[j];
                if (sum >= target) {
                    tmp = j - i + 1;
                    if (min > tmp)    min = tmp;
                    break;
                }
                j++;
            }
            sum = 0;
        }

        return min == 0x7fffffff ? 0 : min;
    }
};

// version 2: 头指针每次移动超过 1
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = (int)nums.size();
        int mini = 0x7fffffff;
        long long sum = 0;

        int i = 0, j = 0;
        while (j < size) {
            sum += nums[j];
            while (sum >= target) {
                mini = min(mini, j - i + 1);
                    
                // 移动头指针，直至 sum <= target
                sum -= nums[i++];
            }
            j++;
        }

        return mini == 0x7fffffff ? 0 : mini;
    }
};
