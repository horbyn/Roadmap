#include <iostream>
#include <queue>
using namespace std;

const int maxn = 30;
struct node_t {
	int data;
	node_t *left;
	node_t *right;
};
int arr_post[maxn], arr_in[maxn];

node_t *create(int postL, int postR, int inL, int inR) {
	/* 递归边界 */
	if (postL > postR)    return NULL;

	/* 递归式 */
	node_t *root = new node_t;
	root->data = arr_post[postR];
	int k;
	for (k = 0; k < inR; ++k)//找到中序的根
		if (arr_post[postR] == arr_in[k])    break;
	int left_num = k - inL;//关键：算出左子树长度

	root->left = create(postL, postL + left_num - 1, inL, k - 1);
	root->right = create(postL + left_num, postR - 1, k + 1, inR);

	return root;
}

void level_traversal(node_t *t) {//类似 BFS() 遍历
	/* 起点入队 */
	queue<node_t *> q;//队列用结点指针类型比较方便
	q.push(t);
	while (!q.empty()) {
		/* 访问队头元素 */
		node_t *top =q.front();
		q.pop();

		if (top == t)    cout << top->data;
		else    cout << " " << top->data;
		/* 遍历队头元素的下一 "广度" 所有元素 */
		if (top->left)    q.push(top->left);
		if (top->right)    q.push(top->right);
	}
}

int main() {
	int n;

	/* 1. 输入 */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> arr_post[i];
	for (int i = 0; i < n; ++i)    cin >> arr_in[i];

	/* 2. 主逻辑 */
	node_t *tree = create(0, n - 1, 0, n - 1);
	level_traversal(tree);

	return 0;
}