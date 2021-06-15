/*
 * 思路: dijkstra() -> dfs()
 *     先直接 dijkstra() 找最短路径, 最后才在所有找到的最短路径上二次筛选出最优解
 */
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 500;
const int inf  = 0x3fffffff;
bool vis[maxn] = { false };
int n, s, num = 0, max_wei = -1;
int g[maxn][maxn];//无向图只能用邻接矩阵(方便)
int dis[maxn], weight[maxn];
vector<int > pre[maxn], path, tmp_path;

void dijkstra() {
	//1. 初始化
	fill(dis, dis + n, inf);
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
		if (u == -1)    return;//当前所有点都已不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v < n; ++v) {
			if (!vis[v] && g[u][v] != inf) {
				if (dis[v] > dis[u] + g[u][v]) {
					dis[v] = dis[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);//v 的前驱是 u
				}
				else if (dis[v] == dis[u] + g[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

void dfs_travesal_path(int v) {
	if (v == s) {
		num++;
		tmp_path.push_back(v);
		//1. 计算路径上的 "次标尺"
		int value = 0;
		for (int i = (int)tmp_path.size() - 1; i >= 0; --i) {
			int idx = tmp_path[i];
			value += weight[idx];
		}
		//2. 找最优 "次标尺"
		if (value > max_wei) {
			max_wei = value;
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
	int e, d;
	cin >> n >> e >> s >> d;
	for (int i = 0; i < n; ++i)    cin >> weight[i];
	fill(g[0], g[0] + maxn * maxn, inf);
	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}

	//2. MAIN LOGIC
	dijkstra();
	dfs_travesal_path(d);

	//3. OUTPUT MODULE
	cout << num << " " << max_wei;

	return 0;
}