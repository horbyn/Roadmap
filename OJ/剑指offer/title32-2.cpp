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
            pair<TreeNode *, int > cur_pair = q.front();
            TreeNode *cur = cur_pair.first;
            int level = cur_pair.second;
            q.pop();
            if (level >= (int)vc.size()) {
                vector<int > tmp;
                tmp.push_back(cur->val);
                vc.push_back(tmp);
            } else     vc[level].push_back(cur->val);

            if (cur->left)    q.push(make_pair(cur->left, level + 1));
            if (cur->right)    q.push(make_pair(cur->right, level + 1));
        }

        return vc;
    }
};
