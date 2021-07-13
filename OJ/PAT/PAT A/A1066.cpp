#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node_t {
	int data, height;
	struct node_t* left, * right;
}node_t;

const int maxn = 20;
int n;

/* 获取高度 */
int get_height(node_t* t) {
	if (t == NULL)    return 0;
	else    return t->height;
}

/* 获取平衡因子: 左子树高度 - 右子树高度 */
int get_balance(node_t* t) {
	return get_height(t->left) - get_height(t->right);
}

/* 更新高度: 左右子树最大者 + 1 */
void update_height(node_t* t) {
	t->height = max(get_height(t->left), get_height(t->right)) + 1;
}

/* RR 型右旋: 即右下变右上 */
void r(node_t*& r) {
	node_t* tmp = r->right;
	r->right = tmp->left;
	tmp->left = r;
	update_height(r);//一定要先低再高。因为先高再低, 低的还没更新, 那么高的就是错的
	update_height(tmp);
	r = tmp;
}

/* LL 型左旋: 即左下变左上 */
void l(node_t*& r) {
	node_t* tmp = r->left;
	r->left = tmp->right;
	tmp->right = r;
	update_height(r);
	update_height(tmp);
	r = tmp;
}

/* AVL 插入: 三部曲: 插入; 更新高度; 判平衡因子 */
void insert(node_t*& t, int v) {
	if (t == NULL) {
		node_t* node = new node_t;
		node->data = v;
		node->height = 1;
		node->left = node->right = NULL;
		t = node;
		return;
	}

	if (v < t->data) {
		//1. 插入
		insert(t->left, v);
		//2. 更新高度
		update_height(t);
		//3. 判平衡因子
		if (get_balance(t) == 2) {
			int ret = get_balance(t->left);
			if (ret == 1)    l(t);	//LL
			else if (ret == -1) {	//LR
				r(t->left);//LR 先 R 后 L
				l(t);
			}
		}
	} else {
		insert(t->right, v);
		update_height(t);
		if (get_balance(t) == -2) {
			int ret = get_balance(t->right);
			if (ret == -1)    r(t);	//RR
			else if (ret == 1) {	//RL
				l(t->right);//RL 先 L 后 R
				r(t);
			}
		}
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	node_t* tree = NULL;
	for (int i = 0; i < n; ++i) {
		int inp;
		cin >> inp;
		/* 2. MAIN LOGIC */
		insert(tree, inp);
	}

	/* 3. OUTPUT MODULE */
	if (tree)    cout << tree->data;

	return 0;
}