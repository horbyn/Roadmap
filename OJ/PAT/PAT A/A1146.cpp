#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1001;
int n, m, k;
int in[maxn];
vector<int > out[maxn], query[maxn], judge;

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		out[u].push_back(v);
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			int inp;
			cin >> inp;
			query[i].push_back(inp);
		}
	}

	/* 2. MAIN LOGIC */
	//计算入度
	for (int i = 1; i <= n; ++i) {
		if (out[i].size()) {
			for (int j = 0; j < (int)out[i].size(); ++j)    in[out[i][j]]++;
		}
	}
	//遍历 query
	for (int i = 0; i < k; ++i) {
		bool flag = true;
		vector<int > in_dup(begin(in), end(in));

		for (int j = 0; j < (int)query[i].size() && flag; ++j) {
			int u = query[i][j];
			if (in_dup[u] == 0) {//只有当入度为 0 时才能摘掉该点
				for (int k = 0; k < (int)out[u].size(); ++k) {
					int v = out[u][k];
					in_dup[v]--;//摘掉该点同时将其出点, 入度--
				}
			} else {
				judge.push_back(i);
				flag = false;
				break;
			}
		}
	}

	/* 3. OUTPUT MODULE */
	cout << judge[0];
	for (int i = 1; i < (int)judge.size(); ++i)    cout << " " << judge[i];

	return 0;
}