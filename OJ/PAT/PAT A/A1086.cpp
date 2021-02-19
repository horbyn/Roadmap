#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct node_t {
	int data;
	node_t *left;
	node_t *right;
};

static node_t *root;//root 保存中序序列遍历完后建立的树的根
static stack<string> s;

node_t *create() {
	if (s.empty() || s.top() == "Pop") {//栈空或遍历到 Pop 时返回NULL
		if (!s.empty())    s.pop();
		return NULL;
	}

	node_t *root = new node_t;
	string str = s.top();
	s.pop();
	if (str.size() == 6)    root->data = str[5] - '0';
	else    root->data = (str[5] - '0') * 10 + str[6] - '0';
	root->left = create();
	root->right = create();

	return root;
}

void post_traversal(node_t *tree) {
	if (tree == NULL)    return;

	post_traversal(tree->left);
	post_traversal(tree->right);
	if (tree == root)    cout << tree->data;//后序最后一个即根结点
	else    cout << tree->data << " ";
}

int main() {
	int n;

	/* 1. 输入 */
	cin >> n;
	cin.ignore();
	vector<string> str;
	string inp;
	for (int i = 0; i < 2 * n; ++i) {//先将输入保存到某个地方
		getline(cin, inp);
		str.push_back(inp);
	}
	vector<string>::iterator it = str.end() - 1;
	for (; it != str.begin(); --it)    s.push(*it);//入栈要反过来这样栈顶才是第一个
	s.push(*it);//for() 遍历到第一个迭代器会退出所以最后还要补上

	/* 2. 主逻辑 */
	node_t *tree = create();
	root = tree;

	/* 3. 输出 */
	post_traversal(tree);

	return 0;
}