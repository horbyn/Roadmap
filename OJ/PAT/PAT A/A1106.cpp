#include <cstdio>
#include <vector>
#pragma warning(disable: 4996)//VS 使用 scanf()
using namespace std;

const int maxn = 100000;
int n, min_num = 0;
double p, r, min_price = (double)0x3fffffff;
vector<int > tree[maxn];//一般树组织: 这里是因为树结点本身不保存信息所以只需记录孩子即可

void dfs(vector<int >& t, double u) {//遍历 root->leaves 用 dfs()
	if (t.empty()) {
		if (u < min_price) {
			min_price = u;
			min_num = 1;
		} else if (u == min_price)    min_num++;
		return;
	}

	u *= 1 + r;
	for (int i = 0; i < (int)t.size(); ++i)    dfs(tree[t[i]], u);
}

int main() {
	/* 1. INPUT MODULE */
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100.0;
	for (int i = 0; i < n; ++i) {
		int num, inp;
		scanf("%d", &num);
		if (num != 0) {
			for (int j = 0; j < num; ++j) {
				scanf("%d", &inp);
				tree[i].push_back(inp);
			}
		}
	}

	/* 2. MAIN LOGIC */
	dfs(tree[0], p);

	/* 3. OUTPUT MODULE */
	printf("%.4lf %d", min_price, min_num);

	return 0;
}