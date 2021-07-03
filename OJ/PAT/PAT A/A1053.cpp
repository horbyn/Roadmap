#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node_t {//一般树组织方式: data + vector
	int          data;
	vector<int > child;
}node_t;

const int maxn = 100;
int n, m, s;
vector<int > path_tmp;
vector<vector<int > > path;
node_t tree[maxn];

bool cmp(vector<int > a, vector<int > b) {//二维数组比较大小的 cmp() 思路: 逐个遍历
	int len = (int)a.size() <= (int)b.size() ? (int)a.size() : (int)b.size();
	for (int i = 0; i < len; ++i) {
		if (a[i] == b[i])    continue;
		else    return a[i] > b[i];
	}
}

void dfs(node_t *node, int sum) {//遍历 root->leaves 用 dfs()
	sum = sum + node->data;
	path_tmp.push_back(node->data);

	if (node->child.empty()) {
		if (sum == s)    path.push_back(path_tmp);
		path_tmp.pop_back();
		return;
	}
	if (sum < s) {
		for (int i = 0; i < (int)node->child.size(); ++i) {
			int child = node->child[i];
			dfs(&tree[child], sum);
		}
	}
	path_tmp.pop_back();
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i) {
		int inp;
		cin >> inp;
		tree[i].data = inp;
	}
	for (int i = 0; i < m; ++i) {
		int node, num;
		cin >> node >> num;
		for (int j = 0; j < num; ++j) {
			int leaf;
			cin >> leaf;
			tree[node].child.push_back(leaf);
		}
	}

	/* 2. MAIN LOGIC */
	dfs(&tree[0], 0);

	/* 3. OUTPUT MODULE */
	sort(path.begin(), path.end(), cmp);
	for (int i = 0; i < (int)path.size(); ++i) {
		cout << path[i][0];
		for (int j = 1; j < (int)path[i].size(); ++j)    cout << " " << path[i][j];
		cout << endl;
	}

	return 0;
}