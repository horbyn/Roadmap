#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct graph_t {
	int level;
	vector<int > followers;
};
static const int maxn = 1001;
static int l, num;
static graph_t user[maxn];
static bool vis[maxn];

void bfs(int u) {
	queue<graph_t > q;
	user[u].level = 0;
	q.push(user[u]);
	vis[u] = true;

	while (!q.empty()) {
		graph_t v = q.front();
		q.pop();
		for (int i = 0; i < (int)v.followers.size() && v.level < l; ++i) {
			int follower = v.followers[i];
			if (!vis[follower]) {
				user[follower].level = v.level + 1;
				num++;
				q.push(user[follower]);
				vis[follower] = true;
			}
		}
	}
}

int main() {
	int n;

	/* 1. INPUT */
	cin >> n >> l;
	for (int i = 1; i <= n; ++i) {
		int m, inp;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			cin >> inp;
			user[inp].followers.push_back(i);
		}
	}

	/* 2. MAIN LOGIC */
	int k, inp;
	cin >> k;
	vector<int > out;
	for (int i = 0; i < k; ++i) {
		cin >> inp;
		num = 0;
		memset(vis, 0, maxn);
		bfs(inp);
		out.push_back(num);
	}

	/* 3. OUTPUT */
	for (int i = 0; i < (int)out.size(); ++i)    cout << out[i] << endl;

	return 0;
}