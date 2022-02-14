// 思路：先中序遍历排序，之后直接返回 size - k 即可
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
    void in_order_traversal(TreeNode *root, vector<int > &v) {
        if (!root)    return;

        in_order_traversal(root->left, v);
        v.emplace_back(root->val);
        in_order_traversal(root->right, v);
    }

    int kthLargest(TreeNode* root, int k) {
        if (!root)    return 0;

        vector<int > vc;
        in_order_traversal(root, vc);
        return vc[(int)vc.size() - k];
    }
};