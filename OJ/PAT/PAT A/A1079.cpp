#include <cstdio>
#include <vector>
#pragma warning(disable: 4996)
using namespace std;

typedef struct node_t {//一般数组织
	double       data;
	vector<int > child;
}node_t;

const int maxn = 100000;
int n;
double p, r, sales = 0.0;
node_t tree[maxn];

void dfs(node_t* t, double u) {//遍历 root->leaves 用 dfs()
	if (t->child.empty()) {
		sales += u * t->data;
		return;
	}

	u *= 1.0 + r;
	for (int i = 0; i < (int)t->child.size(); ++i)
		dfs(&tree[t->child[i]], u);
}

int main() {
	/* 1. INPUT MODULE */
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100.0;
	for (int i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		if (m != 0) {
			int inp;
			for (int j = 0; j < m; ++j) {
				scanf("%d", &inp);
				tree[i].child.push_back(inp);
			}
		} else {
			int inp;
			scanf("%d", &inp);
			tree[i].data = inp;
		}
	}

	/* 2. MAIN LOGIC */
	dfs(&tree[0], p);

	/* 3. OUTPUT MODULE */
	printf("%.1lf", sales);

	return 0;
}