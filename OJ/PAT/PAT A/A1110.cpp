/* 思路: 按完全树编号, 如果编号 == 结点数那就是完全树, 否则编号 > 结点数那就不是 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 20;
int n;
vector<int > inp[maxn];
bool vis[maxn];
int max_idx = -1, max_node = -1;

/* 建树: 同时检查最大下标 */
node_t* create(int d, int i) {//形参 d: 结点数据; 形参 i: 编号
	if (d == -1)    return NULL;

	if (max_idx < i) {
		max_idx = i;//更新最大下标
		max_node = d;//同时记录这个下标对应的结点数据
	}

	node_t* node = new node_t;
	node->data = d;
	node->left = create(inp[d][0], 2 * i);
	node->right = create(inp[d][1], 2 * i + 1);
	return node;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 != "-")    inp[i].push_back(atoi(s1.c_str()));
		else    inp[i].push_back(-1);
		if (s2 != "-")    inp[i].push_back(atoi(s2.c_str()));
		else    inp[i].push_back(-1);
	}

	/* 2. MAIN LOGIC */
	//找根结点
	for (int i = 0; i < n; ++i) {
		if (inp[i][0] != -1 && !vis[inp[i][0]])    vis[inp[i][0]] = true;
		if (inp[i][1] != -1 && !vis[inp[i][1]])    vis[inp[i][1]] = true;
	}
	int root = 0;
	for (; root < n && vis[root]; ++root);
	//建树
	node_t* tree = create(root, 1);

	/* 3. OUTPUT MODULE */
	if (max_idx == n)    cout << "YES " << max_node;
	else if (max_idx > n)    cout << "NO " << root;

	return 0;
}