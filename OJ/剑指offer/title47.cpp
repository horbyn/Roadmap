// 写在前面，这是非常辣鸡的 dfs + 记忆化搜索 方法，时空复杂度惨不忍睹，后续有时间再更新 df + 记忆化搜索法
class Solution {
public:
    int maxi;
    vector<vector<int > > rec;

    void dfs(vector<vector<int>>& g, int v, int r, int c, int x, int y) {
        v += g[x][y];
        if (rec[x][y] < v)    rec[x][y] = v;
        if (x == r - 1 && y == c - 1 && maxi < v) {
            maxi = v;
            return;
        }

        for (int i = 0; i < 2; ++i) {
            if (y + 1 < c && rec[x][y] + g[x][y + 1] > rec[x][y + 1])
                dfs(g, v, r, c, x, y + 1);
            if (x + 1 < r && rec[x][y] + g[x + 1][y] > rec[x + 1][y])
                dfs(g, v, r, c, x + 1, y);
        }
    }

    int maxValue(vector<vector<int>>& grid) {
        int row = (int)grid.size();
        if (row == 0)    return 0;
        int col = (int)grid[0].size();

        vector<int > tmp(col, 0);
        rec.resize(row, tmp);
        maxi = 0;
        dfs(grid, 0, row, col, 0, 0);
        return maxi;
    }
};
