/*
 * 用"根据二叉树特点建树"的方法重做该题发现是 PA, 21/25 测试点五越界, 说明是细节问题
 *     所以不纠结了。
 * 另外我才发现这道题正确思路应该是"根据前序和中序进行建树"。其中, 前序看 Push 序列,
 *     中序看 Pop 序列。这个我确实做两次都没发现..
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 31;
int n, ptr = 0;//指示"栈顶"
string fake_stack[maxn];//"栈"
vector<int > post;

/* 建树: 观察发现 Push 创建的必是左孩子, Pop 分情况讨论 */
node_t* create() {
	node_t* node = new node_t;
	string top = fake_stack[ptr];//"取栈顶"
	ptr++;//"出栈"
	
	if (top.size() > 3) {//"Push"
		int data = atoi(top.erase(0, 5).c_str());//先去掉前 5 个字符, 然后转化为整型
		node->data = data;
		node->left = create();
		if (ptr < n && fake_stack[ptr].size() > 5)    node->right = create();
		else {
			ptr++;
			node->right = NULL;
		}
	} else    return NULL;

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
	n *= 2;
	cin.get();//吃掉上面"cin >> n"的回车
	for (int i = 0; i < n; ++i)    getline(cin, fake_stack[i]);

	/* 2. MAIN LOGIC */
	node_t* tree = create();
	post_travesal(tree);

	/* 3. OUTPUT MODULE */
	cout << post[0];
	for (int i = 1; i < (int)post.size(); ++i)    cout << " " << post[i];

	return 0;
}