class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<string, int > mp;

        for (auto ch : s)    mp[string("") + ch]++;
        for (int i = 0; i < (int)s.size(); ++i)
            if (mp[string("") + s[i]] == 1)    return s[i];

        return ' ';
    }
};
