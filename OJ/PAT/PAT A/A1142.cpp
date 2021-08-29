#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 201, inf = 0x3fffffff;
int nv, ne, m;
int graph[maxn][maxn];
vector<int > query[maxn];
bool inq[maxn];

bool judge_near(int i) {
	for (int j = 0; j < (int)query[i].size() - 1; ++j) {
		int u = query[i][j];
		for (int k = j + 1; k < (int)query[i].size(); ++k) {
			int v = query[i][k];
			if (graph[u][v] == inf)    return false;
		}
	}
	return true;
}

bool judge_max(int i) {
	for (int u = 1; u <= nv; ++u) {
		if (inq[u])    continue;

		int num = 0;//相邻的顶点数
		for (int j = 0; j < (int)query[i].size(); ++j) {

			int v = query[i][j];
			if (graph[u][v] != inf)    num++;//相邻
		}

		if (num == (int)query[i].size())    return false;//任一点与 query[i] 所有都相邻
	}
	return true;
}

int main() {
	/* 0. INITIALIZATION */
	fill(graph[0], graph[0] + maxn * maxn, inf);

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
			int tmp;
			cin >> tmp;
			query[i].push_back(tmp);
		}
	}

	/* 2. MAIN LOGIC */
	for (int i = 0; i < m; ++i) {
		/* 3. OUTPUT MODULE */
		if (judge_near(i) == false)    cout << "Not a Clique\n";
		else {
			//记录 query 有哪些点
			memset(inq, false, sizeof(inq));
			for (int j = 0; j < (int)query[i].size(); ++j)    inq[query[i][j]] = true;

			if (judge_max(i) == false)    cout << "Not Maximal\n";
			else    cout << "Yes\n";
		}
	}

	return 0;
}