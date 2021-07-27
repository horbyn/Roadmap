#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node_t {
	int data, height, idx;
	struct node_t* left, * right;
}node_t;

const int maxn = 20;
int n, idx;
node_t node[maxn];
vector<int > level;

/* AVL 三件套一: 获取高度 */
int get_height(node_t* t) {
	if (t == NULL)    return 0;
	else    return t->height;
}

/* AVL 三件套二: 更新高度 */
void update_height(node_t* t) {
	t->height = max(get_height(t->left), get_height(t->right)) + 1;
}

/* AVL 三件套三: 获取平衡因子 */
int get_balance(node_t* t) {
	return get_height(t->left) - get_height(t->right);
}

/* AVL 基本操作一: 左旋, 适合 LL 型 */
void l(node_t*& t) {
	node_t* tmp = t->left;
	t->left = tmp->right;
	tmp->right = t;
	update_height(t);
	update_height(tmp);
	t = tmp;
}

/* AVL 基本操作二: 右旋, 适合 RR 型 */
void r(node_t*& t) {
	node_t* tmp = t->right;
	t->right = tmp->left;
	tmp->left = t;
	update_height(t);
	update_height(tmp);
	t = tmp;
}

/* AVL 基本操作三: 插入 */
void insert(int v, node_t*& t) {
	//插入三板斧一: 空结点
	if (t == NULL) {
		node_t* node = new node_t;
		node->data = v;
		node->height = 1;
		node->left = node->right = NULL;
		t = node;
		return;
	}

	//插入三板斧二: 待插值小于当前结点, 往左边插
	if (v < t->data) {
		insert(v, t->left);
		//AVL 调整三部曲一: 更新高度
		update_height(t);
		if (get_balance(t) == 2) {//AVL 调整三部曲二: 左插判 L
			int left_bal = get_balance(t->left);
			if (left_bal == 1)    l(t);//AVL 调整三部曲三: L 判 LL/LR
			else if (left_bal == -1) {
				r(t->left);
				l(t);
			}
		}
	} else {//插入三板斧三: 待插值大于当前结点, 往右边插
		insert(v, t->right);
		//AVL 调整三部曲一: 更新高度
		update_height(t);
		if (get_balance(t) == -2) {//AVL 调整三部曲二: 右插判 R
			int right_bal = get_balance(t->right);
			if (right_bal == -1)    r(t);//AVL 调整三部曲三: R 判 RR/RL
			else if (right_bal == 1) {
				l(t->right);
				r(t);
			}
		}
	}
}

/* 更新序号: 用以判断完全树 */
void dfs(int i, node_t* t) {
	if (t == NULL)    return;

	t->idx = i;
	if (t->left)    dfs(2 * i, t->left);
	if (t->right)    dfs(2 * i + 1, t->right);
}

/* 层序遍历 */
void level_travesal(node_t* t) {
	queue<node_t* > q;
	q.push(t);
	while (!q.empty()) {
		node_t* front = q.front();
		q.pop();

		idx = front->idx;//判完全树关键: 序号比结点数量要大, 就不是完全树
		level.push_back(front->data);

		if (front->left)    q.push(front->left);
		if (front->right)    q.push(front->right);
	}
}

int main() {
	/* 1. INPUT MODULE */
	node_t* tree = NULL;
	cin >> n;
	//AVL 建树: 边输入边建树
	for (int i = 0; i < n; ++i) {
		int inp;
		cin >> inp;
		insert(inp, tree);
	}

	/* 2. MAIN LOGIC */
	dfs(1, tree);//更新 AVL 树序号
	level_travesal(tree);

	/* 3. OUTPUT MODULE */
	cout << level[0];
	for (int i = 1; i < (int)level.size(); ++i)    cout << " " << level[i];
	if (idx <= n)    cout << "\nYES";
	else    cout << "\nNO";

	return 0;
}