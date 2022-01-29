/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// 实质是二叉树线索化
class Solution {
public:
    // t 要遍历的树; h 头结点; p 上一个结点
    void dfs(Node* t, Node* &h, Node* &p) {
        if (!t)    return;

        dfs(t->left, h, p);
        t->left = p;                            // 当前结点左孩子指向上一个结点 p
        if (p)    p->right = t;                 // 上一个结点 p 右孩子指向当前结点
        else    h = t;
        p = t;                                  // 调用右孩子递归前，先改上一个结点为自己
        dfs(t->right, h, p);
    }

    Node* treeToDoublyList(Node* root) {
        Node* head = nullptr, * pre = nullptr;
        dfs(root, head, pre);
        if (pre)    pre->right = head;
        if (head)    head->left = pre;
        return head;
    }
};
