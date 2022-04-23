// 题意：删除 s 中某些字符，之后能匹配上字典中的串，那这个串就可能是答案
// 双指针，一个指向 s 另一个指向 dic[]，然后对比
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int idx = -1, size1 = dictionary.size();
        int size2 = s.size(), size3 = 0;

        for (int k = 0; k < size1; ++k) {
            int i = 0, j = 0;
            size3 = dictionary[k].size();

            // 对比 s 与 dic[] 当前串中每个字符
            while (i < size2 && j < size3) {
                if (s[i] == dictionary[k][j]) {
                    ++i;
                    ++j;
                } else    ++i;
            }

            // 字典 dic[] 能够遍历到底说明这个串可能是答案
            if (j == size3) {
                // 第一个串直接赋值
                if (idx == -1)    idx = k;
                // 其他串首先看长度是不是比之前的长
                else if (dictionary[k].size() > dictionary[idx].size())    idx = k;
                // 如果长度一样，就比较字典序
                else if (dictionary[k].size() == dictionary[idx].size()
                            && dictionary[k] < dictionary[idx])    idx = k;
            }
        }

        return idx == -1 ? string("") : dictionary[idx];
    }
};