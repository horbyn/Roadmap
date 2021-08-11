#include <iostream>
#include <vector>
using namespace std;

/* 树结构体 */
typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 1000;
int n;
int Apre[maxn];
vector<int > Vpre, Vpost;

/* 正向建树 */
void create(int v, node_t*& t) {
	if (t == NULL) {
		node_t* node = new node_t;
		node->data = v;
		node->left = node->right = NULL;
		t = node;
		return;
	}

	if (t->data > v)    create(v, t->left);
	else    create(v, t->right);
}

/* 镜像建树 */
void create_mirror(int v, node_t*& t) {
	if (t == NULL) {
		node_t* node = new node_t;
		node->data = v;
		node->left = node->right = NULL;
		t = node;
		return;
	}

	if (t->data <= v)    create_mirror(v, t->left);
	else    create_mirror(v, t->right);
}

/* 前序遍历 */
void pre_order_travesal(node_t* t) {
	if (t == NULL)    return;

	Vpre.push_back(t->data);
	pre_order_travesal(t->left);
	pre_order_travesal(t->right);
}

/* 判断是否同样的前序序列 */
bool judge_pre(node_t *t) {
	Vpre.clear();
	pre_order_travesal(t);

	int i = 0;
	for (; i < n; ++i)
		if (Apre[i] != Vpre[i])    break;
	if (i == n)    return true;
	else    return false;
}

/* 后序遍历 */
void post_order_travesal(node_t* t) {
	if (t == NULL)    return;

	post_order_travesal(t->left);
	post_order_travesal(t->right);
	Vpost.push_back(t->data);
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> Apre[i];

	/* 2. MAIN LOGIC */
	node_t* tree = NULL;
	for (int i = 0; i < n; ++i)    create(Apre[i], tree);//先正向建树
	if (judge_pre(tree)) {//判是否同样的前序序列
		cout << "YES\n";
		post_order_travesal(tree);
		/* 3. OUTPUT MODULE */
		cout << Vpost[0];
		for (int i = 1; i < (int)Vpost.size(); ++i)    cout << " " << Vpost[i];
	} else {
		node_t* tree_mirror = NULL;
		for (int i = 0; i < n; ++i)    create_mirror(Apre[i], tree_mirror);//再镜像建树
		if (judge_pre(tree_mirror)) {//也是判是否同样的前序序列
			cout << "YES\n";
			post_order_travesal(tree_mirror);
			/* 3. OUTPUT MODULE */
			cout << Vpost[0];
			for (int i = 1; i < (int)Vpost.size(); ++i)    cout << " " << Vpost[i];
		} else    cout << "NO";//都不是
	}

	return 0;
}