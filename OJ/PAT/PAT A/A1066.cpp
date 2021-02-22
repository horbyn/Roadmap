#include <iostream>
#include <algorithm>
using namespace std;

struct node_t {
	int data;
	int height;
	node_t* left;
	node_t* right;
};

const int maxn = 20;
int inp[maxn];

node_t* create_node(int val) {
	node_t* n = new node_t;
	n->data = val;
	n->height = 1;
	n->left = n->right = NULL;
	return n;
}

int get_height(node_t* r) {
	if (r == NULL)    return 0;
	return r->height;
}

void update_height(node_t *r) {
	r->height = max(get_height(r->left), get_height(r->right)) + 1;
}

int get_balance(node_t* r) {
	return get_height(r->left) - get_height(r->right);
}

void R(node_t* &r) {
	node_t* tmp = r->left;
	r->left = tmp->right;
	tmp->right = r;
	update_height(r);
	update_height(tmp);
	r = tmp;
}

void L(node_t*& r) {
	node_t* tmp = r->right;
	r->right = tmp->left;
	tmp->left = r;
	update_height(r);
	update_height(tmp);
	r = tmp;
}

void insert(node_t* &r, int val) {
	if (r == NULL) {
		r = create_node(val);
		return;
	}

	if (r->data > val) {
		//1. 插入
		insert(r->left, val);
		//2. 更新高度
		update_height(r);
		//3. 判是否平衡
		if (get_balance(r) == 2) {//左子树不平衡只有 LL 和 LR
			//4. 判是哪种类型的不平衡
			if (get_balance(r->left) == 1) {//LL
				R(r);//LL 右旋调整
			} else {//剩下的情况只有 LR
				L(r->left);//LR 先左旋
				R(r);//再右旋
			}
		}
	} else {
		insert(r->right, val);
		update_height(r);
		if (get_balance(r) == -2) {
			if (get_balance(r->right) == -1) {//RR
				L(r);//RR 左旋
			} else {
				R(r->right);
				L(r);
			}
		}
	}
}

int main() {
	int n;

	/* 1. 输入 */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> inp[i];

	/* 2. 主逻辑 */
	node_t* tree = NULL;
	for (int i = 0; i < n; ++i)    insert(tree, inp[i]);

	/* 3. 输出 */
	if (n != 0)    cout << tree->data << endl;

	return 0;
}