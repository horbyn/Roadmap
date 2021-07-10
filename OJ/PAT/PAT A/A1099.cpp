#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct node_t {
	int idx;
	struct node_t* left, * right;
}node_t;

const int maxn = 100;
int n, Ain[maxn], node_data[maxn];
vector<int > tree[maxn], Vin, level;

/* 建树: 根据邻接表建树, 注意此处树结点实质是 BST 序号 */
node_t* create(int r) {
	node_t* node = new node_t;
	node->idx = r;

	if (tree[r][0] == -1 && tree[r][1] == -1) {
		node->left = node->right = NULL;
	} else if (tree[r][0] != -1 && tree[r][1] == -1) {
		node->left = create(tree[r][0]);
		node->right = NULL;
	} else if (tree[r][0] == -1 && tree[r][1] != -1) {
		node->left = NULL;
		node->right = create(tree[r][1]);
	} else {
		node->left = create(tree[r][0]);
		node->right = create(tree[r][1]);
	}
	return node;
}

/* 中序遍历 */
void in_order_travesal(node_t* t) {
	if (t == NULL)    return;

	in_order_travesal(t->left);
	Vin.push_back(t->idx);
	in_order_travesal(t->right);
}

/* 层序遍历 */
void level_order_travesal(node_t* t) {
	queue<node_t*> q;
	q.push(t);
	while (!q.empty()) {
		node_t* front = q.front();
		q.pop();

		int idx = front->idx;
		level.push_back(node_data[idx]);

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
		tree[i].push_back(l);
		tree[i].push_back(r);
	}
	for (int i = 0; i < n; ++i)    cin >> Ain[i];

	/* 2. MAIN LOGIC */
	node_t* bst = create(0);
	sort(Ain, Ain + n);				//BST 序列中序遍历: BST 中序是有序序列所以直接排序
	in_order_travesal(bst);			//BST 序号中序遍历
	for (int i = 0; i < n; ++i) {	//建立 BST 序号和 BST 结点数据的联系
		int idx = Vin[i];
		node_data[idx] = Ain[i];
	}
	level_order_travesal(bst);		//最后对 BST 结点数据进行中序遍历

	/* 3. OUTPUT MODULE */
	cout << level[0];
	for (int i = 1; i < (int)level.size(); ++i)    cout << " " << level[i];

	return 0;
}