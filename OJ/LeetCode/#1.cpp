class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int > mp;

	for (int i = 0; i < nums.size(); ++i) {
	    map<int, int >::iterator it = mp.find(target - nums[i]);

	    if (it == mp.end())    mp[nums[i]] = i;
	    else    return {it->second, i};//C++ 返回数组可以直接用{}
	}

	return {};
    }
};
