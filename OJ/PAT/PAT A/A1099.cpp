#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct tree_t {
	int data;
	tree_t* left;
	tree_t* right;
};
struct inp_t {
	int left;
	int right;
};

static const int maxn = 100;
static inp_t inp[maxn];
static vector<int> int_keys, level_order;
static int ptr = 0;

static tree_t* dfs_create(int val) {
	tree_t* node = new tree_t;

	if (inp[val].left == -1 && inp[val].right == -1) {
		node->left = node->right = NULL;
		return node;
	}

	if (inp[val].left != -1)
		node->left = dfs_create(inp[val].left);
	else    node->left = NULL;
	if (inp[val].right != -1)
		node->right = dfs_create(inp[val].right);
	else    node->right = NULL;
	return node;
}

static void pre_order_traversal(tree_t* t) {
	if (t == NULL)    return;

	pre_order_traversal(t->left);
	t->data = int_keys[ptr++];
	pre_order_traversal(t->right);
}

static void level_order_traversal(tree_t* t) {
	queue<tree_t*> q;
	q.push(t);
	while (!q.empty()) {
		tree_t* top = q.front();
		q.pop();
		level_order.push_back(top->data);

		if (top->left != NULL)    q.push(top->left);
		if (top->right != NULL)    q.push(top->right);
	}
}

int main() {
	int n, input;

	/* 1. 输入 */
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> inp[i].left >> inp[i].right;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		int_keys.push_back(input);
	}

	/* 2. 主逻辑 */
	tree_t* tree = dfs_create(0);//dfs() 建树
	sort(int_keys.begin(), int_keys.end());
	pre_order_traversal(tree);//先序遍历存放树的数据域
	level_order_traversal(tree);//层序遍历输出

	/* 3. 输出 */
	cout << level_order[0];
	for (unsigned i = 1; i < level_order.size(); ++i)
		cout << " " << level_order[i];

	return 0;
}