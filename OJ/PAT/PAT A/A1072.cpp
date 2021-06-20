#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct graphy_t {
	int v, w;
}graphy_t;
typedef struct outcome_t {
	int idx;
	double aver, dis;
}outcome_t;

const int maxn = 1011;
const int inf  = 0x3fffffff;
bool out_of_range = false, vis[maxn];
int n, m, ds;//顶点数、候选站点个数、服务范围
int dis[maxn];
vector<graphy_t > g[maxn];
vector<outcome_t > out;

bool cmp(outcome_t a, outcome_t b) {
	if (a.dis != b.dis)    return a.dis > b.dis;
	else if (a.aver != b.aver)    return a.aver < b.aver;
	else    return a.idx < b.idx;
}

void dijkstra(int s) {
	//1. 初始化
	memset(vis, false, maxn);
	fill(dis, dis + maxn, inf);
	dis[s] = 0;

	for (int i = 1; i <= n + m; ++i) {
		//2. 找最小
		int min = inf, u = -1;
		for (int j = 1; j <= n + m; ++j) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)    return;//剩余所有点均不连通
		vis[u] = true;

		//3. 松弛
		for (int j = 0; j < (int)g[u].size(); ++j) {
			int v = g[u][j].v;
			if (!vis[v]) {
				if (dis[v] > dis[u] + g[u][j].w) {
					dis[v] = dis[u] + g[u][j].w;
					if (dis[v] > ds) {
						out_of_range = true;
						return;//有一个超出范围都不行
					}
				}
			}
		}
	}
}

int hash_table(char* str) {
	if (str[0] == 'G') {
		str++;
		return atoi(str) + n;
	} else    return atoi(str);
}

int main() {
	//1. INPUT MODULE
	int k;
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	for (int i = 0; i < k; ++i) {
		char str1[8], str2[8];
		int w;
		scanf("%s%s%d", str1, str2, &w);
		int u = hash_table(str1), v = hash_table(str2);
		graphy_t tmp;
		tmp.v = v; tmp.w = w;
		g[u].push_back(tmp);
		tmp.v = u;
		g[v].push_back(tmp);
	}

	//2. MAIN LOGIC
	for (int i = 1; i <= m; ++i) {
		dijkstra(n + i);
		if (out_of_range) {
			out_of_range = false;
			continue;
		}

		//1. 排序
		sort(dis, dis + n + 1);//排序只需要排前面 n 个居民区的点(实际上[0]是 inf, 数组应从[1]开始)
		//2. 算平均值
		double aver = 0.0;
		for (int j = 0; j < n; ++j)    aver += 1.0 * dis[j] / n;
		aver = (int)(aver * 10.0 + 0.5) / 10.0;//四舍五入一位
		//3. 赋值给 outcome_t
		outcome_t tmp;
		tmp.aver = aver; tmp.dis = dis[0]; tmp.idx = i;
		out.push_back(tmp);
	}
	sort(out.begin(), out.end(), cmp);

	//3. OUTPUT MODULE
	if (out.empty())    printf("No Solution\n");
	else    printf("G%d\n%.1lf %.1lf\n", out[0].idx, out[0].dis, out[0].aver);

	return 0;
}