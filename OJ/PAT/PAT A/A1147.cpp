#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxm = 100, maxn = 1000;
int m, n;
int level[maxn], flag[maxm];
vector<int > post[maxm];

/* 建树: 根据层序序列和完全树特点建树 */
node_t* create(int i) {
	if (i >= n)    return NULL;

	node_t* node = new node_t;
	node->data = level[i];
	node->left = create(2 * i + 1);
	node->right = create(2 * i + 2);
	return node;
}

/* 判断最大堆: 遍历当前结点向下的路径, 是否当前结点比下面的结点都要大 */
bool dfs_max(node_t* t, int v) {//t 是当前结点; v 是上层结点的数值
	if (t == NULL)    return true;

	if (t->data > v)    return false;
	if (!dfs_max(t->left, t->data))    return false;
	if (t->right && !dfs_max(t->right, t->data))    return false;
	return true;
}

/* 判断最小堆: 原理类似 */
bool dfs_min(node_t* t, int v) {
	if (t == NULL)    return true;

	if (t->data < v)    return false;
	if (!dfs_min(t->left, t->data))    return false;
	if (t->right && !dfs_min(t->right, t->data))    return false;
	return true;
}

/* 后序遍历 */
void post_travesal(node_t* t, int i) {//由于有多个输入, i 表示当前的序列属于哪个输入
	if (t == NULL)    return;

	post_travesal(t->left, i);
	post_travesal(t->right, i);
	post[i].push_back(t->data);
}

/* 释放树: 因为有多棵树作为输入, 所有每次输入并处理完都要释放 */
void dfs_delete(node_t* pt, node_t* t) {//t 是当前结点, pt 是其父结点
	if (t == NULL)    return;

	dfs_delete(t, t->left);
	dfs_delete(t, t->right);
	pt = NULL;//释放当前结点时, 以防万一让其父结点指向 NULL
	delete t;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		memset(level, 0, sizeof(level));
		for (int j = 0; j < n; ++j)    cin >> level[j];
		
		/* 2. MAIN LOGIC */
		node_t* tree = create(0);
		bool max_flag = dfs_max(tree, level[0]);
		bool min_flag = dfs_min(tree, level[0]);
		if (!max_flag && !min_flag)    flag[i] = -1;//-1 表示不是最大最小堆
		else if (max_flag && !min_flag)    flag[i] = 1;//1 表示最大堆
		else if (!max_flag && min_flag)    flag[i] = 0;//0 表示最小堆

		post_travesal(tree, i);
		dfs_delete(NULL, tree);
	}

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < m; ++i) {
		if (flag[i] == 1)    cout << "Max Heap\n";
		else if (flag[i] == 0)    cout << "Min Heap\n";
		else    cout << "Not Heap\n";

		cout << post[i][0];
		for (int j = 1; j < (int)post[i].size(); ++j)    cout << " " << post[i][j];
		cout << endl;
	}

	return 0;
}