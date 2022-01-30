/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode*& root, string& ret) {
        if (!root) {
            ret += "null,";
            return;
        }

        ret += to_string(root->val) + ",";
        dfs(root->left, ret);
        dfs(root->right, ret);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        dfs(root, ret);
        return ret;
    }

    TreeNode* create(string& str) {
        if (str.empty())    return nullptr;

        if (str[0] == 'n') {
            str.erase(0, 5);
            return nullptr;
        }
        int pos = 0;
        for (; str[pos] != ','; ++pos);
        int val = stoi(str.substr(0, pos));
        str.erase(0, pos + 1);
        TreeNode* n = new TreeNode(val);
        n->left = create(str);
        n->right = create(str);
        return n;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return create(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));