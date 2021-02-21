#include <iostream>
#include <vector>
using namespace std;

/*
暂时发现了一个逻辑错误的例子：
5
2 4 3 5 1
无论是 BST 还是 BST 镜像最后输出应该是 "NO" 而目前程序输出 "YES"

错误原因是：
（如果按 BST 来组织）既然 [1] 比 [0] 大，那么 [1] 后面的结点应该全是右子树————全比 [0] 大；（如果按 BST 镜像来组织）既然 [1] 比 [0] 大，那么 [1]~[3] 应该是左子树————但这棵左子树又不满足 BST 特性

修改了很久都没改出来，所以先放着 :-(
*/

struct node_t {
	int data;
	node_t* left;
	node_t* right;
};

static const int maxn = 1000;
static int tree[maxn];
static bool flag = true;
static vector<int> post_order;//由于打印有格式，所以先统一放入数组

static node_t* pre_order_create(int base, int end) {
	node_t* node = new node_t;
	node->data = tree[base];

	if (base == end) {
		node->left = node->right = NULL;
		return node;
	}

	int l = base + 1, r = end;
	if (tree[base + 1] < node->data) {//左子树比根小
		for (; l <= end && tree[l] < node->data; ++l);//l 遍历结束为第一个右子树结点
		for (; r > base && tree[r] >= node->data; --r);//r 遍历结束为最后一个左子树结点
	} else {
		for (; l <= end && tree[l] >= node->data; ++l);
		for (; r > base && tree[r] < node->data; --r);
	}
	if (l - 1 != r)    flag = false;

	node->left = pre_order_create(base + 1, l - 1);
	if (l <= end)    node->right = pre_order_create(r + 1, end);
	else    node->right = NULL;
	return node;
}

static void post_order_traversal(node_t* t) {
	if (t == NULL)    return;

	post_order_traversal(t->left);
	post_order_traversal(t->right);
	post_order.push_back(t->data);
}

int main() {
	int n;

	/* 1. 输入 */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> tree[i];

	/* 2. 主逻辑 */
	node_t* tree = pre_order_create(0, n - 1);

	/* 3. 输出 */
	if (flag) {
		post_order_traversal(tree);
		cout << "YES\n" << post_order[0];
		for (unsigned i = 1; i < post_order.size(); ++i)
			cout << " " << post_order[i];
	} else    cout << "NO";

	return 0;
}