class Solution {
public:
    string reverseWords(string s) {
        string ret("");
        int j = (int)s.size(), i = j;
        if (j == 0)    return ret;

        s = string(" ") + s;// 最前面添加个空格，否则要另外处理第一个单词
        for (; i >= 0; --i) {
            if (s[i] == ' ') {
                if (i == j)    --j;
                else {
                    ret += s.substr(i + 1, j - i) + string(" ");// 每个单词最后都加空格
                    j = i - 1;
                }
            }
        }
        if (!ret.empty())    ret.erase(ret.end() - 1);// 最后才剔除最后一个空格
        return ret;
    }
};
