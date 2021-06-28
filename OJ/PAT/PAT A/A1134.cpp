#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 10000;
unordered_map<int, bool > vis;
vector<int > g[maxn], query[100];

int main() {
	/* 1. INPUT MODULE */
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int num, inp;
		cin >> num;
		for (int j = 0; j < num; ++j) {
			cin >> inp;
			query[i].push_back(inp);
		}
	}

	/* 2. MAIN LOGIC */
	for (int i = 0; i < k; ++i) {
		int cnt = 0;//边数
		vis.clear();
		for (int j = 0; j < (int)query[i].size(); ++j) {
			int pre = query[i][j];
			for (int edge = 0; edge < (int)g[pre].size(); ++edge) {
				int next = g[pre][edge];
				if (vis[pre * maxn + next] == false) {
					vis[pre * maxn + next] = true;
					vis[next * maxn + pre] = true;
					cnt++;
				}
			}
		}
		/* 3. OUTPUT MODULE */
		if (cnt == m)    cout << "Yes\n";
		else    cout << "No\n";
	}
	return 0;
}