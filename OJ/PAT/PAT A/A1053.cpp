/* PA 27/30 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node_t {//一般树组织
	int weight;
	vector<int > child;
}node_t;

const int maxn = 100;
int n, m, s, ptr = 0;
node_t tree[maxn];
vector<int > path[maxn], tmp;

/* 二维数组比较: 逐个遍历 */
bool cmp(vector<int > a, vector<int > b) {
	int len = a.size() <= b.size() ? a.size() : b.size();
	for (int i = 0; i < len; ++i) {
		if (a[i] == b[i])    continue;
		else    return a[i] > b[i];
	}
}

void dfs(int v, int t) {
	tmp.push_back(tree[t].weight);
	v += tree[t].weight;

	//遍历每个孩子
	for (int i = 0; i < (int)tree[t].child.size(); ++i)
		dfs(v, tree[t].child[i]);
	//判断是否满足条件
	if (tree[t].child.empty() && v == s)
		path[ptr++] = tmp;

	tmp.pop_back();
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i)    cin >> tree[i].weight;
	for (int i = 0; i < m; ++i) {
		int idx, num, inp;
		cin >> idx >> num;
		for (int j = 0; j < num; ++j) {
			cin >> inp;
			tree[idx].child.push_back(inp);
		}
	}

	/* 2. MAIN LOGIC */
	dfs(0, 0);
	sort(path, path + ptr, cmp);

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < ptr; ++i) {
		cout << path[i][0];
		for (int j = 1; j < (int)path[i].size(); ++j)
			cout << " " << path[i][j];
		cout << endl;
	}

	return 0;
}