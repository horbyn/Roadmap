/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)    return {};

        vector<vector<int > > vc;
        queue<pair<TreeNode *, int > > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto cur_pair = q.front();
            auto cur = cur_pair.first;
            auto level = cur_pair.second;
            q.pop();

            if (level >= (int)vc.size()) {
                vector<int > tmp;
                tmp.push_back(cur->val);
                vc.push_back(tmp);
            } else     vc[level].push_back(cur->val);

            if (cur->left)    q.push(make_pair(cur->left, level + 1));
            if (cur->right)    q.push(make_pair(cur->right, level + 1));
        }

        for (int i = 0; i < (int)vc.size(); ++i)
            if (i & 1)    reverse(vc[i].begin(), vc[i].end());

        return vc;
    }
};
