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
    TreeNode *mirrorTree(TreeNode *t) {
        if (t == nullptr)    return nullptr;

        TreeNode *n = new TreeNode(t->val);
        n->left = mirrorTree(t->right);
        n->right = mirrorTree(t->left);
        return n;
    }
};
