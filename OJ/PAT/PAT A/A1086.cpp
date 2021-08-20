#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 31;
int n;
vector<int > pre, in, post;
stack<int > sta;

/* 建树: 根据前中序列建树 */
node_t* create(int preB, int preE, int inB, int inE) {
	if (preB > preE)    return NULL;

	int root = pre[preB];
	int k = 0;
	for (; k <= inE && in[k] != root; ++k);
	int left_len = k - inB;

	node_t* node = new node_t;
	node->data = root;
	node->left = create(preB + 1, preB + left_len, inB, k - 1);
	node->right = create(preB + left_len + 1, preE, k + 1, inE);
	return node;
}

/* 后序遍历 */
void post_travesal(node_t* t) {
	if (t == NULL)    return;

	post_travesal(t->left);
	post_travesal(t->right);
	post.push_back(t->data);
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	cin.get();//前面有 cin, 要调用一次 .get() 吃掉回车
	for (int i = 0; i < 2 * n; ++i) {
		string str;
		getline(cin, str);//因为输入有空格, 所以用 getline() 获取整行
		if (str[1] == 'u') {
			str.erase(str.begin(), str.begin() + 5);
			int dig = atoi(str.c_str());
			sta.push(dig);
			pre.push_back(dig);//入栈序列为先序
		}
		else {
			int dig = sta.top();
			sta.pop();
			in.push_back(dig);///出栈序列为中序
		}
	}

	/* 2. MAIN LOGIC */
	node_t* tree = create(0, n - 1, 0, n - 1);
	post_travesal(tree);

	/* 3. OUTPUT MODULE */
	cout << post[0];
	for (int i = 1; i < (int)post.size(); ++i)    cout << " " << post[i];

	return 0;
}