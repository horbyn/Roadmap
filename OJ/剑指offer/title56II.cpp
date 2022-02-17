class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int > mp;

        for (auto v : nums) {
            unordered_map<int, int >::iterator it = mp.find(v);
            if (it == mp.end())    mp[v] = 1;
            else    mp[v]++;

            if (mp[v] == 3)    mp.erase(it);
        }

        return mp.empty() ? 0 : mp.begin()->first;
    }
};
