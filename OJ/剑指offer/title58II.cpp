class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string sub = s.substr(0, n);
        s.erase(s.begin(), s.begin() + n);
        return s + sub;
    }
};
