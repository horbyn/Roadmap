#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct node_t {
	int depth;
	vector<int> child;
};

static const int maxn = 128;
static int n, max_depth = -1;//总结点数，最大深度
static int level_leaves[maxn];//层数肯定比结点数少，所以长度为结点数肯定够
static node_t tree[maxn];

static void dfs(node_t *t, int d) {
	node_t *cur = t;
	cur->depth = d;
	if (d > max_depth)    max_depth = d;

	if (cur->child.size() == 0)    level_leaves[cur->depth]++;//这一层叶子数累加 1

	for (unsigned i = 0; i < cur->child.size(); ++i)
		dfs(&tree[cur->child[i]], d + 1);
}

int main() {
	int m;

	/* 0. 初始化 */
	for (int i = 0; i < maxn; ++i)    tree[i].child.clear();

	/* 1. 输入 */
	cin >> n >> m;
	if (n == 0)    return 0;
	for (int i = 0; i < m; ++i) {
		int k, idx, inp;
		cin >> idx >> k;
		for (int j = 0; j < k; ++j) {
			cin >> inp;
			tree[idx].child.push_back(inp);
		}
	}

	/* 2. 主逻辑 */
	dfs(&tree[1], 0);

	/* 3. 输出 */
	cout << level_leaves[0];
	for (int i = 1; i <= max_depth; ++i)    cout << " " << level_leaves[i];

	return 0;
}