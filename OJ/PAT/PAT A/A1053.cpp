#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node_t {
	int weight;
	int total_weight;
	vector<int> child;
};

static const int maxn = 100;
static int s, ptr = 0;
static vector<int> temp;
static vector<vector<int> > outp;
static node_t tree[maxn];

bool cmp(vector<int> a, vector<int> b) {
	int i, len = (int)min(a.size(), b.size()) - 1;
	for (i = 0; i < len && a[i] == b[i]; ++i);
	return    a[i] > b[i];
}

void dfs(node_t* t, int w) {
	node_t* cur = t;
	temp.push_back(cur->weight);//尝试当前值

	if (w + cur->weight == s && cur->child.size() == 0) {//权重够了并且当前结点是叶子才能打印
		outp.push_back(temp);
		ptr++;
	}

	for (unsigned i = 0; i < cur->child.size(); ++i)
		dfs(&tree[cur->child[i]], w + cur->weight);
	temp.pop_back();//最后当前结点离开队列
}

int main() {
	int n, m;

	/* 0. 初始化 */
	for (int i = 0; i < maxn; ++i)    tree[i].child.clear();

	/* 1. 输入 */
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i)    cin >> tree[i].weight;
	for (int i = 0; i < m; ++i) {
		int idx, num;
		cin >> idx >> num;
		for (int j = 0; j < num; ++j) {
			int inp;
			cin >> inp;
			tree[idx].child.push_back(inp);
		}
	}

	/* 2. 主逻辑 */
	dfs(&tree[0], 0);
	sort(outp.begin(), outp.end(), cmp);

	/* 3. 输出 */
	for (int i = 0; i < ptr; ++i) {
		cout << outp[i][0];
		for (unsigned j = 1; j < outp[i].size(); ++j)    cout << " " << outp[i][j];
		cout << endl;
	}

	return 0;
}