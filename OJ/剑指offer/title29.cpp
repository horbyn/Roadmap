class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = (int)matrix.size(), col = 0;
        if (!matrix.empty())    col = (int)matrix[0].size();

        vector<int > vc;
        map<pair<int, int >, bool > mp;                     // 记录已访问结点
        int cr = row * col, i = 0, j = 0, ptr = 0;
        int x[4] = { 0, 1, 0, -1 }, y[4] = { 1, 0, -1, 0 };
        while (cr) {
            vc.push_back(matrix[i][j]);
            mp[make_pair(i, j)] = true;
            // 越界或已访问，更换方向
            if (0 > i + x[ptr] || i + x[ptr] >= row
                || 0 > j + y[ptr] || j + y[ptr] >= col
                || mp[make_pair(i + x[ptr], j + y[ptr])])
                ptr = (ptr + 1) % 4;
            i += x[ptr];
            j += y[ptr];
            cr--;
        }

        return vc;
    }
};
