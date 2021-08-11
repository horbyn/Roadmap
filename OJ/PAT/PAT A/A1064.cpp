#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/* 树结构 */
typedef struct node_t {
	int data, idx;
	struct node_t* left, * right;
}node_t;

const int maxn = 1000;
int n;
int ptr = 0, Ain[maxn];
vector<int > Vlevel;

/* 建树: 按序号建完全树 */
node_t* create(int i) {
	if (i > n)    return NULL;

	node_t* node = new node_t;
	node->idx = i;
	node->left = create(2 * i);
	node->right = create(2 * i + 1);
	return node;
}

/* 中序遍历: 此处一边中序遍历, 一边将中序序列放至树相应结点的位置 */
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
	for (int i = 0; i < n; ++i)    cin >> Ain[i];

	/* 2. MAIN LOGIC */
	sort(Ain, Ain + n);//BST 中序有序, 所以直接排序就行
	node_t* tree = create(1);//CBT 特性是序号有规律, 所以用这个规律能搭起树的框架
	in_order_travesal(tree);//CBT 按序号进行中序遍历, 那么遍历的结点就是 BST 中序序列
	level_order_travesal(tree);

	/* 3. OUTPUT MODULE */
	cout << Vlevel[0];
	for (int i = 1; i < (int)Vlevel.size(); ++i)    cout << " " << Vlevel[i];

	return 0;
}