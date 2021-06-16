#include <iostream>
#include <vector>
using namespace std;

const int maxn = 500;
const int inf  = 0x3fffffff;
bool vis[maxn] = { false };
int g[maxn][maxn], cost[maxn][maxn];
int n, s, dis[maxn], min_cost = inf;//顶点数、起点、最短路径、最小花销
vector<int > pre[maxn], path, tmp_path;//前驱、路径序列

void dijkstra() {
	//1. 初始化
	fill(dis, dis + maxn, inf);
	dis[s] = 0;

	for (int i = 0; i < n; ++i) {
		//2. 找最小
		int min = inf, u = -1;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)    return;//当前所有剩余顶点两两不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v < n; ++v) {
			if (!vis[v] && g[u][v] != inf) {
				if (dis[v] > dis[u] + g[u][v]) {
					dis[v] = dis[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[v] = dis[u] + g[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

void dfs_travesal_path(int v) {
	if (v == s) {
		tmp_path.push_back(v);
		int value = 0;
		for (int i = (int)tmp_path.size() - 1; i > 0; --i) {
			int u = tmp_path[i], v = tmp_path[i - 1];
			value += cost[u][v];
		}
		if (value < min_cost) {
			min_cost = value;
			path = tmp_path;
		}
		tmp_path.pop_back();
	}
	else {
		tmp_path.push_back(v);
		for (int i = 0; i < (int)pre[v].size(); ++i)
			dfs_travesal_path(pre[v][i]);
		tmp_path.pop_back();
	}
}

int main() {
	//1. INPUT MODULE
	int m, d;
	cin >> n >> m >> s >> d;
	fill(g[0], g[0] + maxn * maxn, inf);
	fill(cost[0], cost[0] + maxn * maxn, inf);
	for (int i = 0; i < m; ++i) {
		int u, v, dis, cos;
		cin >> u >> v >> dis >> cos;
		g[u][v] = dis; g[v][u] = dis;
		cost[u][v] = cos; cost[v][u] = cos;
	}

	//2. MAIN LOGIC
	dijkstra();
	dfs_travesal_path(d);

	//3. OUTPUT MODULE
	for (int i = (int)path.size() - 1; i >= 0; --i)    cout << path[i] << " ";
	cout << dis[d] << " " << min_cost;

	return 0;
}