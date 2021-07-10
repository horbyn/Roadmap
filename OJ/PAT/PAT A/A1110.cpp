/*
 * PA 15/25, 应该是思路错了
 *    我的思路是完全树有右孩子必有左孩子, 所以若有右孩子但无左孩子则不是完全树
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 20;
int n, last_node;
bool vis[maxn];
vector<int > tree[maxn];

/* 转换字符-整型 */
int trans(char c) {
	if (c != '-')    return c - '0';
	else    return -1;
}

/* 建树: 根据邻接表建树 */
node_t* create(int r) {
	node_t* node = new node_t;
	node->data = r;

	if (tree[r][0] == -1 && tree[r][1] == -1) {
		node->left = node->right = NULL;
	} else if (tree[r][0] == -1 && tree[r][1] != -1) {
		node->left = NULL;
		node->right = create(tree[r][1]);
	} else if (tree[r][0] != -1 && tree[r][1] == -1) {
		node->left = create(tree[r][0]);
		node->right = NULL;
	} else {
		node->left = create(tree[r][0]);
		node->right = create(tree[r][1]);
	}
	return node;
}

/* 层序遍历 */
bool level_travesal(node_t* t) {
	queue<node_t*> q;
	q.push(t);
	while (!q.empty()) {
		node_t* front = q.front();
		q.pop();

		if (front->right && !front->left)    return false;
		last_node = front->data;

		if (front->left)    q.push(front->left);
		if (front->right)    q.push(front->right);
	}
	return true;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char l, r;
		cin >> l >> r;
		int le = trans(l), ri = trans(r);
		tree[i].push_back(le);
		tree[i].push_back(ri);
	}

	/* 2. MAIN LOGIC */
	//找出根结点: 遍历输入邻接表, 没出现的下标即根结点
	int root = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		if (tree[i][0] != -1)    vis[tree[i][0]] = true;
		if (tree[i][1] != -1)    vis[tree[i][1]] = true;
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			root = i;
			break;
		}
	}
	node_t* t = create(root);
	bool flag = level_travesal(t);//层序遍历同时判断是否完全树

	/* 3. OUTPUT MODULE */
	if (flag)    cout << "YES " << last_node;
	else    cout << "NO " << root;

	return 0;
}