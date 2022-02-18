// v1：二分法找另一半，时间复杂度 O(nlogn)，约 193ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = (int)nums.size();

        for (int i = 0; i < size; ++i) {// 外层遍历每一个数
            int find = target - nums[i];
            int left = 0, right = size - 1, mid;
            while (left <= right) {// 内层二分法查找另一个数
                mid = left + ((right - left) >> 1);
                if (nums[mid] == find)    return vector<int > {nums[i], nums[mid]};
                else if (nums[mid] < find)    left = mid + 1;
                else    right = mid - 1;
            }
        }

        return {};
    }
};

// v2：哈希法，时间复杂度按理说 O(n)，但跑得 476ms，可以肯定哈希表开销太大
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = (int)nums.size();
        unordered_map<int, bool > mp;

        for (int i = 0; i < size; ++i) {
            if (mp[nums[i]] == false)    mp[target - nums[i]] = true;
            else    return vector<int > {nums[i], target - nums[i]};
        }

        return {};
    }
};

// v3：双指针法，时间复杂度 O(n)，约 149ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = (int)nums.size();
        int i = 0, j = size - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target)    return vector<int > {nums[i], nums[j]};
            else if (sum > target)    --j;
            else    ++i;
        }
        return vector<int > {};
    }
};