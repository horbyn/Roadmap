#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef struct vertex_t {
	int v, w;
}vertex_t;

typedef struct two_t {
	int s, d;//起点、终点
}two_t;

typedef struct route_t {
	int l, s, d;//Line、对应 Line 上第一个站点、对应 Line 上最后一个站点
}route_t;

const int maxn = 10001, inf = 0x3fffffff;
int n, s, min_trans;//顶点数、起点、最小换乘数
bool vis[maxn] = { false }, is_trans[maxn] = { false };
int dis[maxn];
vector<vertex_t > g[maxn];
vector<int > pre[maxn], path, path_tmp;
vector<int > trans[maxn];//每个站点所属 Line
two_t two[10];

void dijkstra(int s) {
	/* 1. 初始化 */
	memset(vis, false, sizeof(vis));
	fill(dis, dis + maxn, inf);
	dis[s] = 0;

	for (int i = 0; i < n; ++i) {
		/* 2. 找最小 */
		int min = inf, u = -1;
		for (int j = 0; j < maxn; ++j) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)    return;//剩余顶点两两间不连通
		vis[u] = true;

		/* 3. 松弛 */
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

void dfs_travesal(int v) {
	if (v == s) {
		path_tmp.push_back(v);
		/* 1. 遍历路径沿途点 */
		int value = -1;
		for (int i = (int)path_tmp.size() - 1; i >= 0; --i) {
			int u = path_tmp[i], j = 0, line;
			for (; j < (int)trans[u].size(); ++j) {
				//遍历当前站点 u 所有 Line, 是否与上一站点有重复————有重复说明不用换乘
				line = trans[u][j];
				if (is_trans[line])    break;
			}
			memset(is_trans, false, sizeof(is_trans));
			if (j == (int)trans[u].size()) {
				//与所有 Line 都不同那就是换乘
				value++;
				for (j = 0; j < (int)trans[u].size(); ++j) {
					//设置与当前站点 u 的所有 Line 为有联系
					line = trans[u][j];
					is_trans[line] = true;
				}
			}
			else    is_trans[line] = true;
		}
		/* 2. 判断第二标尺 */
		if (value < min_trans) {
			min_trans = value;
			path = path_tmp;
		}
		path_tmp.pop_back();
	} else {
		path_tmp.push_back(v);
		for (int i = 0; i < (int)pre[v].size(); ++i)
			dfs_travesal(pre[v][i]);
		path_tmp.pop_back();
	}
}

int main() {
	/* 1. INPUT MODULE */
	int routes, m, k;
	scanf("%d", &routes);
	for (int i = 0; i < routes; ++i) {
		int u;
		scanf("%d %d", &m, &u);
		trans[u].push_back(i + 1);//当前站点所属 Line
		if (!vis[u]) {
			vis[u] = true;
			n++;//顶点数加一
		}
		for (int j = 1; j < m; ++j) {
			int v;
			scanf("%d", &v);
			vertex_t inp;
			inp.v = v; inp.w = 1;
			g[u].push_back(inp);
			inp.v = u;
			g[v].push_back(inp);
			u = v;
			trans[u].push_back(i + 1);//当前站点所属 Line
			if (!vis[u]) {
				vis[u] = true;
				n++;//顶点数加一
			}
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)    scanf("%d %d", &two[i].s, &two[i].d);

	/* 2. MAIN LOGIC */
	for (int i = 0; i < k; ++i) {
		s = two[i].s;
		dijkstra(s);
		min_trans = inf;
		dfs_travesal(two[i].d);
		printf("%d\n", dis[two[i].d]);

		memset(is_trans, false, sizeof(is_trans));
		vector<route_t > routes;//记录整条路径涉及的换乘信息
		route_t route_tmp;
		int line, pre_line, fst_sta, last_sta = -1;
		for (int j = (int)path.size() - 1; j >= 0; --j) {
			//遍历当前路径看是否有换乘
			int u = path[j], k = 0;
			for (; k < (int)trans[u].size(); ++k) {
				//遍历当前站点 u 所有 Line, 是否与上一站点有重复————有重复说明不用换乘
				line = trans[u][k];
				if (is_trans[line]) {
					pre_line = line;//与上一个 Line 有相同的, 则记录下现在走的 Line
					last_sta = u;//也记录下当前 Line 最后一个 station
					break;
				}
			}
			memset(is_trans, false, sizeof(is_trans));
			if (k == (int)trans[u].size()) {//与所有 Line 都不同那就是换乘
				//记录换乘信息(起点除外————起点还没有涉及换乘)
				if (path[j] != s) {
					route_tmp.l = pre_line;
					route_tmp.s = fst_sta;
					route_tmp.d = last_sta;
					routes.push_back(route_tmp);
				}
				
				for (int l = 0; l < (int)trans[u].size(); ++l) {
					//设置与当前站点 u 的所有 Line 为有联系
					line = trans[u][l];
					is_trans[line] = true;
					if (last_sta == -1)    fst_sta = u;	//每次换乘时起点是上一次最后的 station
					else    fst_sta = last_sta;
					pre_line = line;	//每次换乘时线路是当前 Line
					last_sta = u;		//每次换乘时终点是当前 station
				}
			} else    is_trans[line] = true;
		}
		{//额外保存最后一次换乘信息
			route_tmp.l = pre_line;
			route_tmp.s = fst_sta;
			route_tmp.d = last_sta;
			routes.push_back(route_tmp);
		}

		/* 3. OUTPUT MODULE */
		for (int j = 0; j < (int)routes.size(); ++j) {
			printf("Take Line#%d from %04d to %04d.\n", routes[j].l, routes[j].s, routes[j].d);
		}
	}
	return 0;
}