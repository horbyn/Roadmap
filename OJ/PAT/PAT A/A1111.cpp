#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 501, inf = 0x3fffffff;
bool vis[maxn] = { false };
int n, s, d, min_rate = inf, min_sta = inf;//顶点数、起点、源点、最快、沿途最小站点
int g[maxn][maxn], rate[maxn][maxn], dis[maxn], dis_rate[maxn];
vector<int > pre[maxn], path, tmp_path;
vector<int > pre_rate[maxn], path_rate;

void dijkstra(int s) {
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
		if (u == -1)    return;//剩余点两两间不连通
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

void dijkstra_rate(int s) {
	//1. 初始化
	memset(vis, false, sizeof(vis));
	fill(dis_rate, dis_rate + maxn, inf);
	dis_rate[s] = 0;

	for (int i = 0; i < n; ++i) {
		//2. 找最小
		int min = inf, u = -1;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && dis_rate[j] < min) {
				min = dis_rate[j];
				u = j;
			}
		}
		if (u == -1)    return;//剩余点两两间不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v < n; ++v) {
			if (!vis[v] && rate[u][v] != inf) {
				if (dis_rate[v] > dis_rate[u] + rate[u][v]) {
					dis_rate[v] = dis_rate[u] + rate[u][v];
					pre_rate[v].clear();
					pre_rate[v].push_back(u);
				}
				else if (dis_rate[v] = dis_rate[u] + rate[u][v]) {
					pre_rate[v].push_back(u);
				}
			}
		}
	}
}

void dfs(int v) {
	if (v == s) {
		tmp_path.push_back(v);
		//1. 计算沿途站点边权
		int value = 0;
		for (int i = (int)tmp_path.size() - 1; i > 0; --i) {
			int u = tmp_path[i], v = tmp_path[i - 1];
			value += rate[u][v];
		}
		//2. 判断
		if (value < min_rate) {
			min_rate = value;
			path = tmp_path;
		}
		tmp_path.pop_back();
	} else {
		tmp_path.push_back(v);
		for (int i = 0; i < (int)pre[v].size(); ++i)
			dfs(pre[v][i]);
		tmp_path.pop_back();
	}
}

void dfs_rate(int v) {
	if (v == s) {
		tmp_path.push_back(v);
		//1. 计算沿途站点边权
		int value = 0;
		value = (int)tmp_path.size() - 2;//沿途站点等于扣除起点和终点
		//2. 判断
		if (value < min_sta) {
			min_sta = value;
			path_rate = tmp_path;
		}
		tmp_path.pop_back();
	}
	else {
		tmp_path.push_back(v);
		for (int i = 0; i < (int)pre_rate[v].size(); ++i)
			dfs_rate(pre_rate[v][i]);
		tmp_path.pop_back();
	}
}

int main() {
	//1. INPUT MODULE
	int m;
	cin >> n >> m;
	fill(g[0], g[0] + maxn * maxn, inf);
	fill(rate[0], rate[0] + maxn * maxn, inf);
	for (int i = 0; i < m; ++i) {
		int u, v, flag, w1, w2;
		cin >> u >> v >> flag >> w1 >> w2;
		g[u][v] = w1;
		rate[u][v] = w2;
		if (flag == 0) {
			g[v][u] = w1;
			rate[v][u] = w2;
		}
	}
	cin >> s >> d;

	//2. MAIN LOGIC
	dijkstra(s);
	dfs(d);
	tmp_path.clear();
	dijkstra_rate(s);
	dfs_rate(d);

	//3. OUTPUT MODULE
	if (path == path_rate) {
		cout << "Distance = " << dis[d] << "; Time = " << dis_rate[d] << ": " << s;
		for (int i = (int)path.size() - 2; i >= 0; --i)    cout << " -> " << path[i];
	} else {
		cout << "Distance = " << dis[d] << ": " << s;
		for (int i = (int)path.size() - 2; i >= 0; --i)    cout << " -> " << path[i];
		cout << "\nTime = " << dis_rate[d] << ": " << s;
		for (int i = (int)path_rate.size() - 2; i >= 0; --i)    cout << " -> " << path_rate[i];
	}

	return 0;
}