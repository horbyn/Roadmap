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
    TreeNode *create(const vector<int > &pre, const vector<int > &in, int pL, int pR, int iL, int iR) {
        if (pL > pR)    return nullptr;
        TreeNode* t = new TreeNode(pre[pL]);
        if (pL == pR)    return t;

        // 1. 找根
        int root;
        for (root = iL; root <= iR; ++root)
            if (in[root] == pre[pL])     break;
        
        // 2. 求左子树长度
        int len = root - iL;
        
        // 3. 赋值左右子树
        t->left = create(pre, in, pL + 1, pL + len, iL, root - 1);
        t->right = create(pre, in, pL + len + 1, pR, root + 1, iR);

        return t;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())    return nullptr;

        int n = preorder.size();
        TreeNode *t = create(preorder, inorder, 0, n - 1, 0, n - 1);
        return t;
    }
};
