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
    bool judge(TreeNode *a, TreeNode *b) {
        if (!b)    return true;                 // B 右孩子空但前面都相同其实是 true
        if (!a)    return false;

        if (a->val != b->val)    return false;
        bool left = judge(a->left, b->left);
        bool right = judge(a->right, b->right);
        return left && right;                   // 只有当左右孩子都同是才相同
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)    return false;

        queue<TreeNode * > q;
        q.push(A);
        while (!q.empty()) {
            // A 的每一个结点都要检查
            TreeNode *p = q.front();
            q.pop();

            if (p->val == B->val) {// A B 根相等
                bool ret = judge(p, B);
                if (ret)    return ret;
            }

            if (p->left)    q.push(p->left);
            if (p->right)    q.push(p->right);
        }

        return false;
    }
};
