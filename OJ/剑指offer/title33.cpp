class Solution {
public:
    bool create(vector<int >& in, vector<int >& post, int iL, int iR, int pL, int pR) {
        if (iL > iR)    return true;

        int root = -1;
        for (int k = iL; k <= iR; ++k)
            if (in[k] == post[pR])    { root = k; break; }
        if (root == -1)    return false;

        int len = iR - root;                                        // 右子树长度
        return create(in, post, root + 1, iR, pR - len, pR - 1) && create(in, post, iL, root - 1, pL, pR - len - 1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        int n = (int)postorder.size();
        if (n == 0)    return true;

        vector<int > in{ postorder };
        sort(in.begin(), in.end());                                 // BST 中序有序

        // 判中序和后序是否是同一棵树
        return create(in, postorder, 0, n - 1, 0, n - 1);
    }
};
