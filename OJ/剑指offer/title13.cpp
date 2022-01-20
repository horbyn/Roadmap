// 貌似可优化地方，此处用 map 记录已访问，参考题解用 二维数组 记录已访问
class Solution {
public:
    map<pair<int, int >, bool > mp; // 记录是否已访问
    int ax[4] = {0, 0, -1, 1};
    int ay[4] = {-1, 1, 0, 0};
    int ret;

    int sum(int n) {
        int sum = 0;

        /* 算法一：16ms，击败7.9%
        string sn = to_string(n);
        for (int i = 0; i < (int)sn.size(); ++i)
            sum += sn[i] - '0';
        */
        
        // 算法二：12ms，击败 10.92%
        while (n) {
            int tmp = n % 10;
            sum += tmp;
            n /= 10;
        }

        return sum;
    }

    void dfs(int x, int y, int k, int m, int n) {
        if (sum(x) + sum(y) > k)    return;
        mp[make_pair(x, y)] = true;
        ret++;

        for (int i = 0; i < 4; ++i) {
            int px = x + ax[i], py = y + ay[i];

            if (0 <= px && px < m && 0 <= py && py < n
                && !mp[make_pair(px, py)]) {            // 判越界、判是否已访问
                    dfs(px, py, k, m, n);
                }
        }
    }

    int movingCount(int m, int n, int k) {
        mp.clear();
        ret = 0;

        dfs(0, 0, k, m, n);
        
        return ret;
    }
};
