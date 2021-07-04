#include <cstdio>
#include <vector>
#pragma warning(disable: 4996)//VS 用 scanf() 要加上这句话
using namespace std;

typedef struct node_t {//一般树组织
	double data;
	vector<int > child;
}node_t;

const int maxn = 100000;
int n, num = 0;
double p, r, max_price = -1.0;
node_t tree[maxn];

void dfs(node_t *t, double u) {//遍历 root-leaves 用 dfs()
	if (t->child.empty()) {
		if (u > max_price) {
			max_price = u;
			num = 1;
		}
		else if (u == max_price)    num++;
		return;
	}

	u *= 1 + r;
	for (int i = 0; i < (int)t->child.size(); ++i)
		dfs(&tree[t->child[i]], u);
}

int main() {
	/* 1. INPUT MODULE */
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100.0;
	int root = -1;
	for (int i = 0; i < n; ++i) {
		int inp;
		scanf("%d", &inp);
		if (inp != -1)    tree[inp].child.push_back(i);
		else    root = i;
	}

	/* 2. MAIN LOGIC */
	dfs(&tree[root], p);

	/* 3. OUTPUT MODULE */
	printf("%.2lf %d", max_price, num);

	return 0;
}