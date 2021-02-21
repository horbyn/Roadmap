#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct node_t {
	int depth;
	vector<int> child;
};

static const int maxn = 100000;
static double r;
static int root;
static vector<int> depth_leaves;
static node_t tree[maxn];

static bool cmp(int a, int b) {
	return a > b;
}

static void dfs(node_t* t, int d) {
	node_t* cur = t;
	cur->depth = d;

	if (cur->child.size() == 0) {
		depth_leaves.push_back(d);//保存叶子深度
		return;
	}

	for (unsigned i = 0; i < cur->child.size(); ++i)
		dfs(&tree[cur->child[i]], d + 1);
}

int main() {
	int n;
	double p;

	/* 0. 初始化 */
	for (int i = 0; i < maxn; ++i)    tree[i].child.clear();

	/* 1. 输入 */
	cin >> n >> p >> r;
	r /= 100.0;
	for (int i = 0; i < n; ++i) {
		int inp;
		cin >> inp;
		if (inp == -1)    root = i;
		else    tree[inp].child.push_back(i);//输入反过来处理
	}

	/* 2. 主逻辑 */
	dfs(&tree[root], 0);//执行结束会得到所有叶子的深度
	sort(depth_leaves.begin(), depth_leaves.end(), cmp);//排序
	int max_depth = depth_leaves[0], max_nums = 1;
	for (int i = 1; depth_leaves[i] == max_depth; ++i)
		max_nums++;//找到多少个最大值

	/* 3. 输出 */
	cout << fixed << setprecision(2)
		<< p * pow(1 + r, max_depth)
		<< " " << max_nums;

	return 0;
}