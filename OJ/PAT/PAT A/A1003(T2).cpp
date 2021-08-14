/* 最短路径: 单源 + 双标尺(点权) */
/*
 * 思路: dijkstra() -> dfs()
 *     先直接 dijkstra() 找最短路径, 最后才在所有找到的最短路径上二次筛选出最优解
 */
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 500, inf = 0x3fffffff;
int n, m, c1, c2, max_resc = -1, num = 0;
bool vis[maxn];
int g[maxn][maxn], dis[maxn], weig[maxn];
vector<int > pre[maxn], path, path_tmp;

void dijkstra(int s) {
	//1. 初始化
	fill(dis, dis + maxn, inf);
	dis[s] = 0;

	for (int i = 0; i < n; ++i) {
		//2. 找最小
		int u = -1, min = inf;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)    return;//所有点都已被访问/所有点均不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v < n; ++v) {
			if (!vis[v] && g[u][v] != inf) {
				if (dis[v] > dis[u] + g[u][v]) {
					dis[v] = dis[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] == dis[u] + g[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

void dfs(int u) {
	if (c1 == u) {
		path_tmp.push_back(u);
		num++;
		//1. 遍历路径: 计算次标尺
		int value = 0;
		for (int i = (int)path_tmp.size() - 1; i >= 0; --i) {
			int v = path_tmp[i];
			value += weig[v];
		}
		//2. 比较: 择优
		if (max_resc < value) {
			max_resc = value;
			path = path_tmp;
		}
		path_tmp.pop_back();
	} else {
		path_tmp.push_back(u);
		for (int i = 0; i < (int)pre[u].size(); ++i)    dfs(pre[u][i]);
		path_tmp.pop_back();
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m >> c1 >> c2;
	fill(g[0], g[0] + maxn * maxn, inf);
	for (int i = 0; i < n; ++i)    cin >> weig[i];
	for (int i = 0; i < m; ++i) {
		int u, v, l;
		cin >> u >> v >> l;
		g[u][v] = g[v][u] = l;
	}
	
	/* 2. MAIN LOGIC */
	dijkstra(c1);
	dfs(c2);

	/* 3. OUTPUT MODULE */
	cout << num << " " << max_resc;

	return 0;
}