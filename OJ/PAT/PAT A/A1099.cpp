#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/* 树结构体 */
typedef struct node_t {
	int idx, data;
	struct node_t* left, * right;
}node_t;

const int maxn = 100;
int n;
int ptr = 0, Ain[maxn];
vector<int > inp[maxn], Vlevel;

/* 建树: 根据邻接表建树 */
node_t* create(int v) {
	if (v == -1)    return NULL;

	node_t* node = new node_t;
	node->idx = v;
	node->left = create(inp[v][0]);
	node->right = create(inp[v][1]);
	return node;
}

/* 中序遍历: 此处一边遍历, 一边将中序序列放至当前遍历的结点 */
void in_order_travesal(node_t* t) {
	if (t == NULL)    return;

	in_order_travesal(t->left);
	t->data = Ain[ptr++];
	in_order_travesal(t->right);
}

/* 层序遍历 */
void level_order_travesal(node_t* t) {
	queue<node_t* > q;
	q.push(t);
	while (!q.empty()) {
		node_t* front = q.front();
		q.pop();

		Vlevel.push_back(front->data);
		if (front->left)    q.push(front->left);
		if (front->right)    q.push(front->right);
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		inp[i].push_back(l);
		inp[i].push_back(r);
	}
	for (int i = 0; i < n; ++i)    cin >> Ain[i];

	/* 2. MAIN LOGIC */
	sort(Ain, Ain + n);//BST 中序有序
	node_t* tree = create(0);//按邻接表搭起树框架
	in_order_travesal(tree);//中序遍历后能得到树
	level_order_travesal(tree);

	/* 3. OUTPUT MODULE */
	cout << Vlevel[0];
	for (int i = 1; i < (int)Vlevel.size(); ++i)    cout << " " << Vlevel[i];

	return 0;
}