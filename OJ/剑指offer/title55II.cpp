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
    int dfs(TreeNode *r, bool &f) {
        if (!r)    return 0;

        int left_height = dfs(r->left, f);
        int right_height = dfs(r->right, f);
        if (abs(left_height - right_height) > 1 && f)    f = false;
        return max(left_height, right_height) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool flag = true;
        dfs(root, flag);
        return flag;
    }
};
