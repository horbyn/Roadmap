/*
 * 思路: 一边 dijkstra(), 一边记录第二标尺信息, 最后直接输出最优解
 */
#include <iostream>
using namespace std;

#define INF 0x3fffffff
const int maxn = 500;
int n;
int g[maxn][maxn], dis[maxn], weight[maxn];
int w[maxn], nums[maxn];
bool vis[maxn] = { false };

void dijkstra(int s) {
	//1. 初始化
	fill(dis, dis + maxn, INF);
	memset(w, 0, sizeof(w));
	memset(nums, 0, sizeof(nums));
	dis[s] = 0; w[s] = weight[s]; nums[s] = 1;

	for (int i = 0; i < n; ++i) {
		//2. 找最小
		int min = INF, u = -1;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = i;
			}
		}
		if (u == -1)    return;
		vis[u] = true;

		//3. 松弛
		for (int v = 0; v < n; ++v) {
			if (g[u][v] != INF && !vis[v]) {
				if (dis[v] > dis[u] + g[u][v]) {
					dis[v] = dis[u] + g[u][v];
					w[v] = w[u] + weight[v];
					nums[v] = nums[u];
				} else if (dis[v] == dis[u] + g[u][v]) {
					if (w[v] < w[u] + weight[u])    w[v] = w[u] + weight[v];
					nums[v] += nums[u];
				}
			}
		}
	}
}

int main() {
	//1. INPUT
	int e, s, d;
	cin >> n >> e >> s >> d;
	for (int i = 0; i < n; ++i)    cin >> weight[i];
	fill(g[0], g[0] + maxn * maxn, INF);
	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}

	//2. MAIN LOGIC
	dijkstra(s);

	//3. OUTPUT MODULE
	cout << nums[d] << " " << w[d];

	return 0;
}