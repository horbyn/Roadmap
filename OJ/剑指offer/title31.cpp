class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int > s;
        int i = 0, j = 0, m = (int)pushed.size(), n = (int)popped.size();

        while (i < m) {
            if (i < m)    s.push(pushed[i++]);
            while (!s.empty() && j < n && s.top() == popped[j]) { s.pop(); ++j; }
        }

        return s.empty();
    }
};
