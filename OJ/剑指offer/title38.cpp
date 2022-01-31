class Solution {
public:
    int cap;
    vector<bool > vis;
    unordered_set<string > st;

    void dfs(vector<string > &ret, string &ori, string &tmp, int idx) {
        if (idx >= cap) {
            if (st.find(tmp) == st.end()) {
                st.insert(tmp);
                ret.emplace_back(tmp);
            }
            return;
        }

        for (int i = 0; i < cap; ++i) {
            if (!vis[i]) {
                tmp[idx] = ori[i];
                vis[i] = true;
                dfs(ret, ori, tmp, idx + 1);
                vis[i] = false;
            }
        }
    }

    vector<string> permutation(string s) {
        cap = (int)s.size();
        if (cap == 0)    return {};

        vis.resize(cap, false);
        vector<string > ret;
        string str(cap, '\0');
        dfs(ret, s, str, 0);
        return ret;
    }
};
