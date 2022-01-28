/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(vector<vector<int > >& v1, vector<int >& v2, TreeNode* r, int s, int t) {
        v2.emplace_back(r->val);
        if (s + r->val == t && !r->left && !r->right) {
            v1.emplace_back(v2);
            return;
        }

        if (r->left) {
            dfs(v1, v2, r->left, s + r->val, t);
            v2.pop_back();
        }
        if (r->right) {
            dfs(v1, v2, r->right, s + r->val, t);
            v2.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (!root)    return {};

        vector<vector<int > > ret;
        vector<int > tmp;
        dfs(ret, tmp, root, 0, target);
        return ret;
    }
};
