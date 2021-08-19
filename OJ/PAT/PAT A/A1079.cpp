#include <cstdio>
#include <vector>
#include <cmath>
#pragma warning(disable: 4996)
using namespace std;

typedef struct node_t {
	int product;
	vector<int > child;
}node_t;

const int maxn = 100000;
int n;
double p, r, tot = 0.0;
node_t tree[maxn];
double rate[maxn];

void dfs(int r, int t) {
	for (int i = 0; i < (int)tree[t].child.size(); ++i)
		dfs(r + 1, tree[t].child[i]);
	tot += tree[t].product * rate[r] * p;//商品数量 * 比例 * 根单价
}

int main() {
	/* 1. INPUT MODULE */
	scanf("%d%lf%lf", &n, &p, &r);
	r = r / 100.0 + 1.0;
	for (int i = 0; i < n; ++i) {
		int flag;
		scanf("%d", &flag);
		if (flag > 0) {
			for (int j = 0; j < flag; ++j) {
				int inp;
				scanf("%d", &inp);
				tree[i].child.push_back(inp);
			}
		} else if (flag == 0) {
			scanf("%d", &tree[i].product);
		}
	}

	/* 2. MAIN LOGIC*/
	for (int i = 0; i < maxn; ++i)    rate[i] = pow(r, i);//初始化比例数组
	dfs(0, 0);

	/* 3. OUTPUT MODULE */
	printf("%.1lf", tot);

	return 0;
}