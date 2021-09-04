#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 500, inf = 0x3fffffff;
int n, m, s, d;
int graph[maxn][maxn], dis[maxn];
int graph_time[maxn][maxn], dis_fast[maxn];
int min_time = inf, min_num = inf;
bool vis[maxn];
vector<int > pre_dis[maxn], path_dis, path_tmp;
vector<int > pre_fast[maxn], path_fast;

void dijkstra_dis(int s) {
	//1. 初始化
	memset(vis, false, sizeof(vis));
	fill(dis, dis + maxn, inf);
	dis[s] = 0;

	for (int i = 0; i < n; ++i) {
		//2. 找最小
		int min = inf, u = -1;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && min > dis[j]) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)    return;//当前所有点都遍历完, 或当前所有点都不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v < n; ++v) {
			if (!vis[v] && graph[u][v] != inf) {
				if (dis[v] > dis[u] + graph[u][v]) {
					dis[v] = dis[u] + graph[u][v];
					pre_dis[v].clear();
					pre_dis[v].push_back(u);
				} else if (dis[v] == dis[u] + graph[u][v])
					pre_dis[v].push_back(u);
			}
		}
	}
}

void dijkstra_fast(int s) {
	//1. 初始化
	memset(vis, false, sizeof(vis));
	fill(dis_fast, dis_fast + maxn, inf);
	dis_fast[s] = 0;

	for (int i = 0; i < n; ++i) {
		//2. 找最小
		int min = inf, u = -1;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && min > dis_fast[j]) {
				min = dis_fast[j];
				u = j;
			}
		}
		if (u == -1)    return;//当前所有点都遍历完, 或当前所有点都不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v < n; ++v) {
			if (!vis[v] && graph_time[u][v] != inf) {
				if (dis_fast[v] > dis_fast[u] + graph_time[u][v]) {
					dis_fast[v] = dis_fast[u] + graph_time[u][v];
					pre_fast[v].clear();
					pre_fast[v].push_back(u);
				}
				else if (dis_fast[v] == dis_fast[u] + graph_time[u][v])
					pre_fast[v].push_back(u);
			}
		}
	}
}

void dfs_dis(int u) {
	if (u == s) {
		path_tmp.push_back(u);
		//1. 遍历路径
		int value = 0;
		for (int i = (int)path_tmp.size() - 1; i > 0; --i) {
			int cur = path_tmp[i], nxt = path_tmp[i - 1];
			value += graph_time[cur][nxt];
		}
		//2. 择优: 找符合题意的最值
		if (min_time > value) {
			min_time = value;
			path_dis = path_tmp;
		}
		path_tmp.pop_back();
	} else {
		path_tmp.push_back(u);
		for (int i = 0; i < (int)pre_dis[u].size(); ++i)    dfs_dis(pre_dis[u][i]);
		path_tmp.pop_back();
	}
}

void dfs_fast(int u) {
	if (u == s) {
		path_tmp.push_back(u);
		//1. 遍历路径
		int value = (int)path_tmp.size() - 1;
		//2. 择优: 找符合题意的最值
		if (min_num > value) {
			min_num = value;
			path_fast = path_tmp;
		}
		path_tmp.pop_back();
	} else {
		path_tmp.push_back(u);
		for (int i = 0; i < (int)pre_fast[u].size(); ++i)    dfs_fast(pre_fast[u][i]);
		path_tmp.pop_back();
	}
}

int main() {
	/* 0. INITIALIZATION */
	fill(graph[0], graph[0] + maxn * maxn, inf);
	fill(graph_time[0], graph_time[0] + maxn * maxn, inf);

	/* 1. INPUT MODULE */
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v1, v2, flag, dis, tim;
		cin >> v1 >> v2 >> flag >> dis >> tim;
		if (flag == 1) {
			graph[v1][v2] = dis;
			graph_time[v1][v2] = tim;
		} else {
			graph[v1][v2] = graph[v2][v1] = dis;
			graph_time[v1][v2] = graph_time[v2][v1] = tim;
		}
	}
	cin >> s >> d;

	/* 2. MAIN LOGIC */
	dijkstra_dis(s);
	dfs_dis(d);
	path_tmp.clear();
	dijkstra_fast(s);
	dfs_fast(d);

	/* 3. OUTPUT MODULE */
	if (path_dis == path_fast) {
		cout << "Distance = " << dis[d] << "; Time = " << dis_fast[d] << ": ";
		for (int i = (int)path_dis.size() - 1; i >= 0; --i) {
			cout << path_dis[i];
			if (i != 0)    cout << " -> ";
		}
	} else {
		cout << "Distance = " << dis[d] << ": ";
		for (int i = (int)path_dis.size() - 1; i >= 0; --i) {
			cout << path_dis[i];
			if (i != 0)    cout << " -> ";
		}
		cout << "\nTime = " << dis_fast[d] << ": ";
		for (int i = (int)path_fast.size() - 1; i >= 0; --i) {
			cout << path_fast[i];
			if (i != 0)    cout << " -> ";
		}
	}

	return 0;
}