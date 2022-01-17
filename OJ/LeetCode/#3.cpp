/*
    思路：用 map 记录重复字符，用滑动窗口记录最长子串
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int > mp;// 字符->下标
        int cur = 0, max = 0;// 记录上一次子串的位置, 最长的长度

        int i = 0;
        while (i < s.size()) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;
                cur++;
                i++;
            } else {
                if (max < cur)    max = cur;
                cur = 0;
                i = mp[s[i]] + 1;
                mp.clear();
            }
        }
        if (max < cur)    max = cur;

        return max;
    }
};
