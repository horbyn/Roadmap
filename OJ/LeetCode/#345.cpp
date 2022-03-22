/*
 * two pointers:
 * 其实可以用 list 之类的容器处理元音字母
 */

class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i'
            || c == 'o' || c == 'u')    return true;
        else    return false;
    }

    string reverseVowels(string s) {
        int i = 0, j = (int)s.size() - 1;

        while (i < j) {
            while (i < j && !isVowel(s[j]))    --j;
            while (i < j && !isVowel(s[i]))    ++i;

            if (s[i] != s[j])    swap(s[i], s[j]);
            --j; ++i;
        }

        return s;
    }
};
