/* PA, 19/25 */
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 200;
int nv, ne, m;
int graph[maxn][maxn];
vector<int > query[maxn];

int main() {
	/* 1. INPUT MODULE */
	cin >> nv >> ne;
	for (int i = 0; i < ne; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int inp;
			cin >> inp;
			query[i].push_back(inp);
		}
	}

	/* 2. MAIN LOGIC */
	for (int i = 0; i < m; ++i) {
		bool flag = true;
		//判 query 里给出的顶点是否两两相邻
		for (int j = 0; j < (int)query[i].size() && flag; ++j) {
			int u = query[i][j];
			for (int k = j + 1; k < (int)query[i].size() && flag; ++k) {
				int v = query[i][k];
				if (graph[u][v] == 0)    flag = false;
			}
		}
		/* 3. OUTPUT MODULE */
		if (!flag) {
			cout << "Not a Clique\n";
			continue;
		}

		//判若多加入一个顶点是否还能两两相邻
		int u = 1;
		for (; u <= nv; ++u) {//图点集: 遍历每个顶点[1, nv]
			int num = 0;
			for (int j = 0; j < (int)query[i].size(); ++j) {
				int v = query[i][j];
				if (u == v)    break;//跳过已在 query 内的顶点

				if (graph[u][v] == 1)    num++;//当前顶点 u 与 query[] 元素相邻
			}
			if (num == (int)query[i].size()) {//与 query[] 每一个都相邻那么 num = size
				/* 3. OUTPUT MODULE */
				cout << "Not Maximal\n";
				break;
			}
		}
		/* 3. OUTPUT MODULE */
		if (u == nv + 1)    cout << "Yes\n";
	}

	return 0;
}