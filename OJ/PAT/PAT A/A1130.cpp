/* PA 24/25 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct node_t {
	string data;
	struct node_t* left, * right;
}node_t;

typedef struct inp_t {
	string data;
	int left, right;
}inp_t;

const int maxn = 21;
int n;
inp_t inp[maxn];
bool vis[maxn];
vector<string > str;

node_t* create(int i) {
	if (i == -1)    return NULL;

	node_t* node = new node_t;
	node->data = inp[i].data;
	node->left = create(inp[i].left);
	node->right = create(inp[i].right);
	return node;
}

void travesal(node_t* t) {
	if (t == NULL)    return;

	travesal(t->left);
	travesal(t->right);
	if (t->left == NULL && t->right == NULL)    str.push_back(t->data);
	else {
		if (t->left && t->right) {
			string s;
			int left = (int)str.size() - 2, right = left + 1;
			s = "(" + str[left] + t->data + str[right] + ")";
			str.erase(str.end() - 2, str.end());//删除是左闭右开
			str.push_back(s);
		} else if (t->left == NULL && t->right) {
			string s;
			int right = (int)str.size() - 1;
			s = "(" + t->data + str[right] + ")";
			str.erase(str.end() - 1, str.end());
			str.push_back(s);
		}
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> inp[i].data >> inp[i].left >> inp[i].right;
		if (inp[i].left != -1)    vis[inp[i].left] = true;
		if (inp[i].right != -1)    vis[inp[i].right] = true;
	}

	/* 2. MAIN LOGIC */
	//找根结点: 遍历邻接表的孩子表, 没有出现那个就是根
	int root = 1;
	for (; root <= n && vis[root]; ++root);
	node_t* tree = create(root);
	travesal(tree);
	//脱去一前一后两个括号
	str[0].erase(str[0].begin());
	str[0].erase(str[0].end() - 1);

	/* 3. OUTPUT MODULE */
	cout << str[0];

	return 0;
}