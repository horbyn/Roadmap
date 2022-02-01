class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int > mp;
        int ans = 0;
        for (auto v : nums) {
            if (mp.find(v) == mp.end())    mp[v] = 1;
            else    mp[v]++;

            if (mp[ans] < mp[v])    ans = v;
        }
        return ans;
    }
};
