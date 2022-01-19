class Solution {
public:
    typedef struct node_t {
        int x, y;

        node_t(int _x, int _y) : x(_x), y(_y) {}
    }node;

    int x[4] = { 0, 1, 0, -1 };
    int y[4] = { 1, 0, -1, 0 };
    map<pair<int, int >, bool > mp;// 记录已入队的点

    bool sub_dfs(vector<vector<char>>& board, string word, int ptr, int i, int j) {
        if (board[i][j] != word[ptr])    return false;
        ptr++;
        bool ret = false;

        for (int k = 0; k < 4; ++k) {
            if (ptr >= (int)word.size())    return true;

            int px = i + x[k], py = j + y[k];
            if (0 <= px && px < (int)board.size()
                && 0 <= py && py < (int)board[0].size()
                && !mp[make_pair(px, py)]) {//判越界、未访问
                mp[make_pair(px, py)] = true;
                ret = ret || sub_dfs(board, word, ptr, px, py);
                mp[make_pair(px, py)] = false;
            }
        }
        return ret;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j) {
        mp.clear();
        mp[make_pair(i, j)] = true;

        return sub_dfs(board, word, 0, i, j);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int ret = false;
        for (int i = 0; i < (int)board.size() && !ret; ++i)
            for (int j = 0; j < (int)board[0].size() && !ret; ++j)
                if (board[i][j] == word[0])    ret = dfs(board, word, i, j);

        return ret;
    }
};
