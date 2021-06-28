#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct node_t {
	string data;
	struct node_t *left;
	struct node_t *right;
}node_t;

typedef struct inp_t {
	string data;
	int left, right;
}inp_t;

const int maxn = 21;
inp_t inp[maxn];
bool flag[maxn] = { false };
vector<string > ans;

node_t *create_tree(int i) {
	node_t* node = new node_t;
	node->data = inp[i].data;
	if (inp[i].left == -1 && inp[i].right == -1)    node->left = node->right = NULL;
	else {
		if (inp[i].left != -1)    node->left = create_tree(inp[i].left);
		else    node->left = NULL;
		if (inp[i].right != -1)    node->right = create_tree(inp[i].right);
		else    node->right = NULL;
	}
	return node;
}

void dfs_inorder_travesal(node_t *t) {
	if (t == NULL)    return;

	/* 1. 中序遍历 */
	dfs_inorder_travesal(t->left);
	dfs_inorder_travesal(t->right);
	ans.push_back(t->data);

	/* 2. 处理小括号 */
	string s;
	int idx = ans.size() - 2;//ans 保存顺序: 左右根, 因此 size() - 2 表示最后一个孩子
	if (t->left && t->right) {//左右孩子都有
		//idx 是最后一个孩子即右孩子, 其前面是左孩子
		s += "(" + ans[idx - 1] + t->data + ans[idx] + ")";
		ans.erase(ans.end() - 3, ans.end());//清理已经处理的结点
		ans.push_back(s);
	} else if (t->left && !t->right) {//只有左孩子没有右孩子
		//idx 是最后一个孩子此时就是左孩子
		s += "(" + ans[idx] + t->data + ")";
		ans.erase(ans.end() - 2, ans.end());//清理已经处理的结点
		ans.push_back(s);
	} else if (!t->left && t->right) {//没有左孩子只有右孩子
		//idx 是最后一个孩子此时就是右孩子
		s += "(" + t->data + ans[idx] + ")";
		ans.erase(ans.end() - 2, ans.end());//清理已经处理的结点
		ans.push_back(s);
	}
}

int main() {
	//1. INPUT MODULE
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)    cin >> inp[i].data >> inp[i].left >> inp[i].right;

	//2. MAIN LOGIC
	node_t *tree = new node_t;
	int root;
	//找树根: 从前往后遍历静态树, 指针域没出现的 index 就是根
	for (int i = 1; i <= n; ++i) {
		if (inp[i].left != -1)    flag[inp[i].left] = true;
		if (inp[i].right != -1)    flag[inp[i].right] = true;
	}
	for (int i = 1; i <= n; ++i) {
		if (!flag[i])    root = i;
	}
	tree = create_tree(root);
	dfs_inorder_travesal(tree);
	//剔除外围小括号: 如果遇到第一个小括号后, 第二个不是小括号, 则剔除
	for (int i = 0; i < (int)ans[0].size(); ++i) {
		if (ans[0][i] == '(' && ans[0][i + 1] != '(') {
			ans[0].erase(ans[0].begin());
			ans[0].erase(ans[0].end() - 1);
			break;
		}
	}

	//3. OUTPUT MODULE
	cout << ans[0] << endl;

	return 0;
}