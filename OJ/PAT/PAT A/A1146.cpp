#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1001;
int n, m, k;
int degree[maxn], query[maxn][maxn];
int duplication[maxn];
vector<int > graph[maxn], outcome;

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		degree[v]++;//统计入度
	}
	cin >> k;
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < n; ++j)
			cin >> query[i][j];

	/* 2. MAIN LOGIC */
	for (int i = 0; i < k; ++i) {
		//copy 入度
		for (int j = 1; j <= n; ++j)    duplication[j] = degree[j];

		//遍历 query[i]
		for (int j = 0; j < n; ++j) {
			int u = query[i][j];
			if (duplication[u] != 0) {
				outcome.push_back(i);
				break;
			}

			for (int k = 0; k < (int)graph[u].size(); ++k) {
				int v = graph[u][k];
				duplication[v]--;
			}
		}
	}

	/* 3. OUTPUT MODULE */
	if (!outcome.empty())    cout << outcome[0];
	for (int i = 1; i < (int)outcome.size(); ++i)    cout << " " << outcome[i];

	return 0;
}