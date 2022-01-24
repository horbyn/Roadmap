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
    TreeNode *generate_mirror(TreeNode *t) {
        if (!t)    return nullptr;

        TreeNode *n = new TreeNode(t->val);
        n->left = generate_mirror(t->right);
        n->right = generate_mirror(t->left);
        return n;
    }
    
    // 判两树相同
    bool is_same(TreeNode *a, TreeNode *b) {
        if (!a && !b)    return true;                   // 大家都是 nullptr
        if (!a || !b)    return false;                  // 有一个是 nullptr

        // 大家都非 nullptr
        return a->val == b->val && is_same(a->left, b->left) && is_same(a->right, b->right);
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode *mirror = generate_mirror(root);

        return is_same(root, mirror);
    }
};
