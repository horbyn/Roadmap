#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 200, inf = 0x3fffffff;
int n, k;
int path_num = 0, max_happiness = -1, max_aver_happiness = -1;
int graph[maxn][maxn], happiness[maxn], dis[maxn];
bool vis[maxn];
map<string, int > s2i;
map<int, string > i2s;
vector<int > pre[maxn], path, path_tmp;

void dijkstra() {
	//1. 初始化
	memset(vis, false, sizeof(vis));
	fill(dis, dis + maxn, inf);
	dis[0] = 0;

	for (int i = 0; i < n; ++i) {
		//2. 选最小
		int u = -1, min = inf;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && min > dis[j]) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)    return;//所有点都遍历完或当前所有点都不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v < n; ++v) {
			if (graph[u][v] != inf && !vis[v]) {
				if (dis[v] > dis[u] + graph[u][v]) {
					dis[v] = dis[u] + graph[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[v] == dis[u] + graph[u][v])
					pre[v].push_back(u);
			}
		}
	}
}

void dfs(int u) {
	if (u == 0) {
		path_tmp.push_back(u);
		path_num++;
		//1. 遍历所有路径
		int value = 0;
		for (int i = (int)path_tmp.size() - 1; i >= 0; --i) {
			int v = path_tmp[i];
			value += happiness[v];
		}
		int aver_value = value / ((int)path_tmp.size() - 1);
		//2. 择优: 筛选符合题意的最值
		if (max_happiness < value) {
			max_happiness = value;
			max_aver_happiness = aver_value;
			path = path_tmp;
		}
		else if (max_happiness == value) {
			if (max_aver_happiness < aver_value) {
				max_aver_happiness = aver_value;
				path = path_tmp;
			}
		}
		path_tmp.pop_back();
	} else {
		path_tmp.push_back(u);
		for (int i = 0; i < (int)pre[u].size(); ++i)    dfs(pre[u][i]);
		path_tmp.pop_back();
	}
}

int main() {
	/* 0. INITIALIZATION */
	fill(graph[0], graph[0] + maxn * maxn, inf);

	/* 1. INPUT MODULE */
	string base;
	cin >> n >> k >> base;
	s2i[base] = 0; i2s[0] = base;
	for (int i = 1; i <= n - 1; ++i) {
		string str;
		cin >> str >> happiness[i];
		s2i[str] = i; i2s[i] = str;
	}
	for (int i = 0; i < k; ++i) {
		string c1, c2;
		int cost;
		cin >> c1 >> c2 >> cost;
		graph[s2i[c1]][s2i[c2]] = graph[s2i[c2]][s2i[c1]] = cost;
	}

	/* 2. MAIN LOGIC */
	dijkstra();
	dfs(s2i["ROM"]);

	/* 3. OUTPUT MODULE */
	cout << path_num << " " << dis[s2i["ROM"]] << " "
		<< max_happiness << " " << max_aver_happiness << endl;
	for (int i = (int)path.size() - 1; i >= 0; --i) {
		cout << i2s[path[i]];
		if (i != 0)    cout << "->";
	}

	return 0;
}