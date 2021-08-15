/* PA: 24/30 */
/* 最短路径: 单源 + 三标尺(点权) */
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 500, inf = 0x3fffffff;
int cm, n, sp, m;
int min_sent = inf, min_back = inf;
bool vis[maxn];
int g[maxn][maxn], dis[maxn], nums[maxn];
vector<int > pre[maxn], path, path_tmp;

void dijkstra() {
	//1. 初始化
	fill(dis, dis + maxn, inf);
	dis[0] = 0;

	for (int i = 0; i <= n; ++i) {
		//2. 找最小
		int u = -1, min = inf;
		for (int j = 0; j <= n; ++j) {
			if (!vis[j] && min > dis[j]) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)    return;//所有点均遍历完或不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v <= n; ++v) {
			if (!vis[v] && g[u][v] != inf) {
				if (dis[v] > dis[u] + g[u][v]) {
					dis[v] = dis[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] == dis[u] + g[u][v])
					pre[v].push_back(u);
			}
		}
	}
}

void dfs(int u) {
	if (u == 0) {
		path_tmp.push_back(u);
		//1. 遍历路径: 累加标尺
		int value = 0;
		for (int i = 0; i < (int)path_tmp.size() - 1; ++i) {
			//累加沿途站点所有的单车数
			int v = path_tmp[i];
			value += nums[v - 1];
		}
		int station_nums = (int)path_tmp.size() - 1;//沿途站点数
		int perfer = station_nums * (cm / 2);
		int sent = 0, back = 0;
		if (value < perfer) {//沿途单车数 vs. perfer 状态
			//小于 perfer 状态那就 PBMC 发送更多的, 所以 sent 是正数; 肯定不用带回
			sent = perfer - value;
			back = 0;
		} else {
			//多于 perfer 状态那就 PBMC 一辆都不需要发送, 反而需要带回
			sent = 0;
			back = value - perfer;
		}
		//2. 比较标尺: 择优
		if (min_sent > sent) {
			min_sent = sent;
			min_back = back;
			path = path_tmp;
		} else if (min_sent == sent && min_back > back) {
			min_back = back;
			path = path_tmp;
		}
		path_tmp.pop_back();
	}
	else {
		path_tmp.push_back(u);
		for (int i = 0; i < (int)pre[u].size(); ++i)    dfs(pre[u][i]);
		path_tmp.pop_back();
	}
}

int main() {
	/* 1. INPUT MODULE */
	fill(g[0], g[0] + maxn * maxn, inf);
	cin >> cm >> n >> sp >> m;
	for (int i = 0; i < n; ++i)    cin >> nums[i];
	for (int i = 0; i < m; ++i) {
		int u, v, t;
		cin >> u >> v >> t;
		g[u][v] = g[v][u] = t;
	}

	/* 2. MAIN LOGIC */
	dijkstra();
	dfs(sp);

	/* 3. OUTPUT MODULE */
	cout << min_sent << " ";
	for (int i = (int)path.size() - 1; i >= 0; --i) {
		cout << path[i];
		if (i != 0)    cout << "->";
	}
	cout << " " << min_back;

	return 0;
}