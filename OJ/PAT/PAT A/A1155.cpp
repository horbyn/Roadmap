#include <iostream>
#include <vector>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 1000;
int n, level[maxn], ptr = 0;
vector<int > path[maxn], path_tmp;

/* 建树: 根据完全树序号和层序序列建树 */
node_t* create(int i) {
	if (i >= n)    return NULL;

	node_t* node = new node_t;
	node->data = level[i];
	node->left = create(2 * i + 1);
	node->right = create(2 * i + 2);
	return node;
}

/* 判最大堆(同A1147思路): 遍历当前结点向下的路径, 是否当前结点比下面的结点都要大 */
bool dfs_max(int v, node_t* t) {//t 是当前结点; v 是上层结点的数值
	if (t == NULL)    return true;
	if (t->data > v)    return false;

	path_tmp.push_back(t->data);
	if (t->right && !dfs_max(t->data, t->right))    return false;
	if (!dfs_max(t->data, t->left))    return false;
	
	if (!t->left && !t->right)    path[ptr++] = path_tmp;
	path_tmp.pop_back();

	return true;
}

/* 判断最小堆(同A1147思路): 原理类似 */
bool dfs_min(int v, node_t* t) {
	if (t == NULL)    return true;
	if (t->data < v)    return false;

	path_tmp.push_back(t->data);
	if (t->right && !dfs_min(t->data, t->right))    return false;
	if (!dfs_min(t->data, t->left))    return false;

	if (!t->left && !t->right)    path[ptr++] = path_tmp;
	path_tmp.pop_back();

	return true;
}

/* 输入非堆路径: 由于上面两种思路不是堆会直接返回, 所以不是堆要额外遍历一次路径 */
void dfs_right_left_travesal(node_t* t) {
	if (t == NULL)    return;

	path_tmp.push_back(t->data);
	if (t->right)    dfs_right_left_travesal(t->right);
	dfs_right_left_travesal(t->left);

	if (!t->left && !t->right)    path[ptr++] = path_tmp;
	path_tmp.pop_back();
}

/* 释放树 */
void dfs_delete(node_t* pt, node_t* t) {//t 当前结点, pt 当前结点的父结点
	if (t == NULL)    return;

	dfs_delete(t, t->left);
	dfs_delete(t, t->right);
	pt = NULL;
	delete t;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> level[i];

	/* 2. MAIN LOGIC */
	node_t* tree = create(0);
	if (dfs_max(level[0], tree)) {									//先判最大堆
		/* 3. OUTPUT MODULE */
		for (int i = 0; i < ptr; ++i) {
			cout << path[i][0];
			for (int j = 1; j < (int)path[i].size(); ++j)    cout << " " << path[i][j];
			cout << endl;
		}
		cout << "Max Heap";
	} else {														//再判最小堆
		path_tmp.clear();
		ptr = 0;
		if (dfs_min(level[0], tree)) {
			/* 3. OUTPUT MODULE */
			for (int i = 0; i < ptr; ++i) {
				cout << path[i][0];
				for (int j = 1; j < (int)path[i].size(); ++j)    cout << " " << path[i][j];
				cout << endl;
			}
			cout << "Min Heap";
		} else {													//最后才轮到非堆
			path_tmp.clear();
			ptr = 0;
			dfs_right_left_travesal(tree);
			/* 3. OUTPUT MODULE */
			for (int i = 0; i < ptr; ++i) {
				cout << path[i][0];
				for (int j = 1; j < (int)path[i].size(); ++j)    cout << " " << path[i][j];
				cout << endl;
			}
			cout << "Not Heap";
		}
	}

	dfs_delete(NULL, tree);
	return 0;
}