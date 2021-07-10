#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 1001;
int n;
int Ain[maxn], level[maxn];
vector<int > Vin;

/* 建树: 建立关于 CBT 序号的树 */
node_t* create(int i) {
	if (i >= n)    return NULL;

	node_t* node = new node_t;
	node->data = i;
	node->left = create(i * 2 + 1);
	node->right = create(i * 2 + 2);
	return node;
}

/* 中序遍历 */
void in_order_travesal(node_t* t) {
	if (t == NULL)    return;

	in_order_travesal(t->left);
	Vin.push_back(t->data);
	in_order_travesal(t->right);
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> Ain[i];

	/* 2. MAIN LOGIC */
	//1. 中序遍历 BST: 由于 BST 中序是有序序列, 所以排序相当于进行了一次中序遍历
	sort(Ain, Ain + n);
	//2. 中序遍历 CBT 序号: 即构建关于完全二叉树序号的树
	//    根据序号建树, 根结点序号为 0
	node_t* tree = create(0);
	//3. 建立 CBT 序号和 BST 结点的对应关系
	in_order_travesal(tree);
	for (int i = 0; i < n; ++i) {
		int idx = Vin[i];
		level[idx] = Ain[i];
	}

	/* 3. OUTPUT MODULE */
	cout << level[0];
	for (int i = 1; i < n; ++i)    cout << " " << level[i];//层序序列实质上是顺序输出

	return 0;
}