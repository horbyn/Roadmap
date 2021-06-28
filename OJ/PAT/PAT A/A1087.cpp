#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int maxn = 201, inf = 0x3fffffff;
bool vis[maxn] = { false };
int n, nums, max_hap = -1;//顶点数、最短路径数、最大点权
double max_aver = -1.0;//最大平均点权
int g[maxn][maxn], dis[maxn], happy[maxn];
string s;//源点
vector<int > pre[maxn], path, tmp_path;
map<string, int > city;
map<int, string > idx;

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
		if (u == -1)    return;//剩余顶点两两间不连通
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v < n; ++v) {
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

void dfs(int v) {
	if (v == city[s]) {
		tmp_path.push_back(v);
		nums++;
		//1. 计算沿途点权
		int value = 0;
		double aver = 0.0;
		for (int i = (int)tmp_path.size() - 2; i >= 0; --i) {
			int v = tmp_path[i];
			value += happy[v];
		}
		aver = 1.0 * value / ((int)tmp_path.size() - 1);
		//2. 判断
		if (value > max_hap) {
			max_hap = value;
			max_aver = aver;
			path = tmp_path;
		} else if (value == max_hap && aver > max_aver) {
			max_aver = aver;
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

int main() {
	//1. INPUT MODULE
	int k;
	cin >> n >> k >> s;
	city[s] = 0;
	idx[0] = s;
	for (int i = 1; i < n; ++i) {
		string inp_s;
		int inp_i;
		cin >> inp_s >> inp_i;
		city[inp_s] = i;
		idx[i] = inp_s;
		happy[i] = inp_i;
	}
	happy[0] = 0;
	fill(g[0], g[0] + maxn * maxn, inf);
	for (int i = 0; i < k; ++i) {
		string s1, s2;
		int w;
		cin >> s1 >> s2 >> w;
		g[city[s1]][city[s2]] = g[city[s2]][city[s1]] = w;
	}

	//2. MAIN LOGIC
	dijkstra(city[s]);
	dfs(city["ROM"]);

	//3. OUTPUT MODULE
	cout << nums << " " << dis[city["ROM"]] << " "
		<< max_hap << " " << (int)max_aver << "\n" << s;
	for (int i = (int)path.size() - 2; i >= 0; --i)    cout << "->" << idx[path[i]];

	return 0;
}