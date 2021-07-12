/* 实际上题目给出的红黑树 5 个属性, 只需要判 (2)(4)(5) 即可
 *     ————对于(1)每个结点黑色或红色, 题目输入已经限制了;
 *     对于(3), 意思是红黑树中不画出来的才是叶子————这其实也
 *     对解题没什么用
 * (5) 说路径上什么什么, 不用看直接 dfs()
 * (4) 说若一个结点是负数那么他的孩子都是正数————可以用 bfs()
 *     也可以用 dfs(), 反正就是每遍历一个结点同时访问其孩子而
 *     已。那么综合 (5), 直接用 dfs() 一步到位更方便
 * 那么这样便确定了这道题的思路必定是 dfs() (当然建树那是后话)
 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

typedef struct seq_t {
	int val, sign;
}seq_t;

const int maxk = 30, maxn = 30;
int k, n, in[maxn];
seq_t pre[maxn];
bool outcome[maxn];

/* 双序建树: 根据前序和中序建树 */
node_t* create(int preB, int preE, int inB, int inE) {
	if (preB > preE)    return NULL;

	//找根结点并且划分左右子树
	node_t* node = new node_t;
	node->data = pre[preB].val * pre[preB].sign;
	int root = inB;
	for (; root <= inE; ++root) {
		if (in[root] == pre[preB].val)    break;
	}
	int len = root - inB;

	node->left = create(preB + 1, preB + len, inB, root - 1);
	node->right = create(preB + len + 1, preE, root + 1, inE);
	return node;
}

/* 判断红黑树 */
int dfs(node_t* t) {
	if (t == NULL)    return 0;

	//属性4: 如果一个结点是红色(负数), 那么他的所有孩子都是黑色(正数)
	if (t->data < 0) {
		if (t->left && t->right)//如果存在左右孩子
			if (t->left->data <= 0 || t->right->data <= 0)    return -1;//如果左右孩子有一个是红色
		if (t->left && !t->right)
			if (t->left->data <= 0)    return -1;
		if (!t->left && t->right)
			if (t->right->data <= 0)    return -1;
	}

	//属性5: 每个结点到叶子的路径上, 黑色(正数)结点的数目要相等————实际一个结点往下只有两条路径, 所以 dfs() 其左右子树就相当于遍历了所有路径
	int black_num_left = dfs(t->left);
	if (black_num_left == -1)    return -1;
	int black_num_right = dfs(t->right);
	if (black_num_right == -1)    return -1;

	if (black_num_left != black_num_right)    return -1;//遍历完后若所有路径黑色结点数目不一致

	if (t->data > 0)    return black_num_left + 1;//如果当前结点是黑色, 那么返回值 + 1
	else    return black_num_left;
}

/* 释放树: 由于这里一个输入有多个 case, 所以必须释放树所有结点 */
void dfs_delete(node_t* pt, node_t* t) {
	if (t == NULL)    return;

	dfs_delete(t, t->left);
	dfs_delete(t, t->right);
	pt = NULL;
	delete t;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int inp;
			cin >> inp;
			pre[j].val = abs(inp);
			if (inp < 0)    pre[j].sign = -1;
			else    pre[j].sign = 1;
		}

		/* 2. MAIN LOGIC */
		//属性2: 根结点必须是黑色(正数)
		if (pre[0].val * pre[0].sign < 0) {
			outcome[i] = false;
			continue;
		}
		for (int m = 0; m < n; ++m)    in[m] = pre[m].val;
		sort(in, in + n);//获得中序序列(小声BB: 红黑树也是 BST)
		node_t* tree = create(0, n - 1, 0, n - 1);//根据前序和中序创建树
		int ret = dfs(tree);
	
		if (ret == -1)    outcome[i] = false;
		else    outcome[i] = true;
		
		dfs_delete(NULL, tree);
	}
		
	/* 3. OUTPUT MODULE */
	for (int i = 0; i < k; ++i) {
		if (outcome[i])    cout << "Yes\n";
		else    cout << "No\n";
	}

	return 0;
}