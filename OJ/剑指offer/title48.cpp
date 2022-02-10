// v1：一旦遇到重复字符，就从重复字符下一个位置重新开始数数，耗时约 700ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int > mp;// 字符->下标
        int cur = 0, max = 0;// 记录当前不重复子串长度, 最长的长度

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

// v2：滑动窗口版本，一旦遇到重复字符，只改变头指针而尾指针不动，耗时约 12ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int > mp;
        int size = (int)s.size(), maxi = 0, tmp = 0;

        int i = 0, j = 0;// ij 框住滑动窗口
        while (j < size) {
            // 有重复字符出现，并且重复字符在滑动窗口内
            if (mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
                tmp = j - i;
            }
            mp[s[j]] = j;
            ++j;
            ++tmp;
            if (maxi < tmp)    maxi = tmp;
        }

        return maxi;
    }
};