/* 最短路径: 单源 + 双标尺(边权) */
#include <iostream>
#include <vector>
using namespace std;

typedef struct vertex_t {
	int v, w, c;
}ver_t;

const int maxn = 500, inf = 0x3fffffff;
int n, m, s, d, min_cost = inf;
bool vis[maxn];
int dis[maxn];
vector<ver_t > g[maxn];
vector<int > pre[maxn], path, path_tmp;

void dijkstra(int s) {
	//1. 初始化
	fill(dis, dis + maxn, inf);
	dis[s] = 0;

	for (int i = 0; i < n; ++i) {
		//2. 找最小
		int u = -1, min = inf;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && min > dis[j]) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)    return;//所有点都遍历完或所有点均不连通
		vis[u] = true;

		//3. 松弛
		for (int j = 0; j < (int)g[u].size(); ++j) {
			int v = g[u][j].v;
			if (!vis[v]) {
				if (dis[v] > dis[u] + g[u][j].w) {
					dis[v] = dis[u] + g[u][j].w;
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] == dis[u] + g[u][j].w)
					pre[v].push_back(u);
			}
		}
	}
}

void dfs(int u) {
	if (u == s) {
		path_tmp.push_back(u);
		//1. 遍历路径: 计算标尺
		int value = 0;
		for (int i = (int)path_tmp.size() - 1; i > 0; --i) {
			int f = path_tmp[i], r = path_tmp[i - 1];
			for (int j = 0; j < (int)g[f].size(); ++j) {//邻接表找边要一个个遍历
				if (g[f][j].v == r) {
					r = j;
					break;
				}
			}
			value += g[f][r].c;
		}
		//2. 比较: 择优
		if (min_cost > value) {
			min_cost = value;
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
	cin >> n >> m >> s >> d;
	for (int i = 0; i < m; ++i) {
		int u, v, dis, cost;
		cin >> u >> v >> dis >> cost;
		ver_t tmp;
		tmp.v = u; tmp.c = cost; tmp.w = dis;
		g[v].push_back(tmp);
		tmp.v = v;
		g[u].push_back(tmp);
	}

	/* 2. MAIN LOGIC */
	dijkstra(s);
	dfs(d);

	/* 3. OUTPUT MODULE */
	for (int i = (int)path.size() - 1; i >= 0; --i)    cout << path[i] << " ";
	cout << dis[d] << " " << min_cost;

	return 0;
}