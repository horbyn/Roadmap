class Solution {
public:
    vector<int> printNumbers(int n) {
        int cr = 0;
        // hash 转化
        for (int i = 1; i <= n; ++i)
            cr = cr * 10 + 9;
        
        // MAIN LOGIC
        vector<int > vc;
        for (int i = 1; i <= cr; ++i)
            vc.push_back(i);
        return vc;
    }
};
