/* 思路: 和前中之类的建树不同, 前中建树是根据根区分左右子树; 前后建树是根据左子树根右子树根区分左右子树的————前序的左子根, 在后序中肯定是最后一个出现的 */
/* PS. 不过我也不清楚怎么区分唯不唯一, 是直接用左右子树长度为负数来区分的————因为例子里输出 No 就是这种情况, 但具体原理不清楚(反正 AC 后就没管了) */
#include <iostream>
#include <vector>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 30;
int n;
int pre[maxn], post[maxn];
bool flag = true;//假设唯一
vector<int > in;

/* 建树: 根据前后序列建树 */
node_t* create(int preB, int preE, int postB, int postE) {
	if (preE - preB < 0) {//左右子树长度为负数, 可以视为不唯一
		flag = false;
		return NULL;//那就随便令一个孩子结点为 NULL, 即返回 NULL
	} else if (preE - preB == 0) {//左右子树长度为 0, 即当前这一个元素单独成一棵树
		node_t* node = new node_t;
		node->data = pre[preB];
		node->left = node->right = NULL;
		return node;
	} else {
		int left_root = pre[preB + 1], root = postB;//左子树根结点 = 前序第二个
		for (; root <= postE && post[root] != left_root; ++root);//左子树根在后序的下标
		int left_len = root - postB;//左子树长

		node_t* node = new node_t;
		node->data = pre[preB];
		node->left = create(preB + 1, preB + 1 + left_len, postB, root);
		node->right = create(preB + 1 + left_len + 1, preE, root + 1, postE - 1);
		return node;
	}
}

/* 后序遍历 */
void in_order_travesal(node_t* t) {
	if (t == NULL)    return;

	in_order_travesal(t->left);
	in.push_back(t->data);
	in_order_travesal(t->right);
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> pre[i];
	for (int i = 0; i < n; ++i)    cin >> post[i];

	/* 2. MAIN LOGIC */
	node_t* tree = create(0, n - 1, 0, n - 1);
	in_order_travesal(tree);

	/* 3. OUTPUT MODULE */
	if (flag == true)    cout << "Yes\n";
	else    cout << "No\n";
	cout << in[0];
	for (int i = 1; i < (int)in.size(); ++i)    cout << " " << in[i];

	return 0;
}