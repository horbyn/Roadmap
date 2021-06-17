#include <iostream>
#include <vector>
using namespace std;

const int maxn = 500;
const int maxc = 100;
const int inf  = 0x3fffffff;
bool vis[maxn];
int g[maxn][maxn], bikes[maxn], dis[maxn];
int n, s, max_cap, min_bikes = inf, ret = inf;//顶点数、源点、最大点权、最小单车数、要归还的单车数
vector<int > pre[maxn], path, tmp_path;

void dijkstra() {
	//1. 初始化
	fill(dis, dis + maxn, inf);
	dis[s] = 0;

	for (int i = 0; i <= n; ++i) {
		//2. 找最小
		int min = inf, u = -1;
		for (int j = 0; j <= n; ++j) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)    return;//剩余所有顶点均不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v <= n; ++v) {
			if (!vis[v] && g[u][v] != inf) {
				if (dis[v] > dis[u] + g[u][v]) {
					dis[v] = dis[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] = dis[u] + g[u][v])
					pre[v].push_back(u);
			}
		}
	}
}

void dfs_travesal_path(int v) {
	if (v == s) {
		int collect = 0, need = 0;
		for (int i = (int)tmp_path.size() - 1; i >= 0; --i) {
			//找出每条路径上一共差多少辆单车(变量 need 记录); 以及一共收集了多少辆单车
			int u = tmp_path[i];
			if (bikes[u] >= max_cap / 2)    collect += bikes[u] - max_cap / 2;//当前单车点有余, 收集
			else {//当前单车点没米下锅, 先看看之前收集的够不够补
				int diff = max_cap / 2 - bikes[u];//差多少辆单车？
				if (collect >= diff)    collect -= diff;//PBMC 沿途劫富济贫后可以补充
				else {
					need += diff - collect;//PBMC 沿途劫富济贫还不够补, 劫来的全部补充, 然后再由 PBMC 提供
					collect = 0;
				}
			}
		}
		if (need < min_bikes) {
			min_bikes = need;
			ret = collect;
			path = tmp_path;
		} else if (need == min_bikes && collect < ret) {
			ret = collect;
			path = tmp_path;
		}
	} else {
		tmp_path.push_back(v);
		for (int i = 0; i < (int)pre[v].size(); ++i)
			dfs_travesal_path(pre[v][i]);
		tmp_path.pop_back();
	}
}

int main() {
	//1. INPUT MODULE
	int sp, m;
	cin >> max_cap >> n >> sp >> m;
	for (int i = 1; i <= n; ++i)    cin >> bikes[i];
	fill(g[0], g[0] + maxn * maxn, inf);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
	}

	//2. MAIN LOGIC
	dijkstra();
	s = 0;
	dfs_travesal_path(sp);

	//3. OUTPUT LOGIC
	cout << min_bikes << " 0";
	for (int i = (int)path.size() - 1; i >= 0; --i)    cout << "->" << path[i];
	cout << " " << ret;

	return 0;
}