#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct node_t {
	double weight;
	vector<int> child;
};

static const int maxn = 100000;
static double r, sales = 0.0;
static int ptr = 0;
static node_t tree[maxn];

void dfs(node_t* t, double w) {
	node_t* cur = t;

	if (cur->weight != tree[0].weight) {//根单独处理
		if (cur->child.size())    cur->weight = w * (1 + r);//非叶结点
		else    sales += w * (1 + r) * cur->weight;//叶结点
	}

	for (unsigned i = 0; i < cur->child.size(); ++i)
		dfs(&tree[cur->child[i]], cur->weight);
}

int main() {
	int n;

	/* 0. 初始化 */
	for (int i = 0; i < maxn; ++i)    tree[i].child.clear();

	/* 1. 输入 */
	cin >> n >> tree[0].weight >> r;
	r /= 100.0;
	for (int i = 0; i < n; ++i) {
		int m, inp;
		cin >> m;
		if (m == 0) {
			cin >> inp;
			tree[i].weight = (double)inp;
		} else {
			for (int j = 0; j < m; ++j) {
				cin >> inp;
				tree[i].child.push_back(inp);
			}
		}
	}

	/* 2. 主逻辑 */
	dfs(&tree[0], 0.0);

	/* 3. 输出 */
	cout << fixed << setprecision(1) << sales;

	return 0;
}