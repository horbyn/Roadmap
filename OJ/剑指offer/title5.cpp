class Solution {
public:
    string replaceSpace(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                // 1. 删除空格
                s.erase(i, 1);

                // 2. 插入 %20
                s.insert(i, "%20");
            }
        }

        return s;
    }
};
