#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 11;
int n;
bool vis[maxn] = { false };
vector<int > inp[maxn], level, in;

/* 输入转换: 字符-整数 */
int hash_trans(char c) {
	if (c == '-')    return -1;
	else    return c - '0';
}

/* 建树: 这里是根据邻接表建树 */
node_t* create(int r) {
	node_t* node = new node_t;
	node->data = r;
	if (inp[r][0] != -1 && inp[r][1] == -1) {//只有左孩子
		node->left = create(inp[r][0]);
		node->right = NULL;
	}
	else if (inp[r][0] == -1 && inp[r][1] != -1) {//只有右孩子
		node->left = NULL;
		node->right = create(inp[r][1]);
	}
	else if (inp[r][0] == -1 && inp[r][1] == -1) {//没有孩子, 也是边界条件
		node->left = node->right = NULL;
	}
	else {
		node->left = create(inp[r][0]);
		node->right = create(inp[r][1]);
	}
	return node;
}

/* 层序遍历: 这里涉及反转, 但核心都是 bfs() 广度搜索 */
void level_order(node_t* t) {
	memset(vis, false, sizeof(vis));
	queue<node_t* > q;
	q.push(t);
	vis[t->data] = true;
	while (!q.empty()) {
		node_t* front = q.front();
		q.pop();
		level.push_back(front->data);

		if (front->right && !vis[front->right->data]) {
			q.push(front->right);
			vis[front->right->data] = true;
		}
		if (front->left && !vis[front->left->data]) {
			q.push(front->left);
			vis[front->left->data] = true;
		}
	}
}

/* 中序遍历: 这里也涉及反转, 但核心就是二叉树递归遍历那个模板 */
void in_order(node_t* t) {
	if (t == NULL && t == NULL)    return;

	if (t->right)    in_order(t->right);
	in.push_back(t->data);
	if (t->left)    in_order(t->left);
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char left, right;
		cin >> left >> right;
		inp[i].push_back(hash_trans(left));
		inp[i].push_back(hash_trans(right));
	}

	/* 2. MAIN LOGIC */
	int root;
	//以下两个 for(), 找根结点: 观察输入发现没出现的数字下标就是根结点
	for (int i = 0; i < n; ++i) {
		if (inp[i][0] != -1)    vis[inp[i][0]] = true;
		if (inp[i][1] != -1)    vis[inp[i][1]] = true;
	}
	for (int i = 0; i < n; ++i) {
		if (vis[i] != true) {
			root = i;
			break;
		}
	}
	node_t* tree = create(root);
	level_order(tree);
	in_order(tree);

	/* 3. OUTPUT MODULE */
	cout << level[0];
	for (int i = 1; i < (int)level.size(); ++i)    cout << " " << level[i];
	cout << "\n" << in[0];
	for (int i = 1; i < (int)in.size(); ++i)    cout << " " << in[i];

	return 0;
}