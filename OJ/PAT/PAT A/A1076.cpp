#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef struct vertex_t {
	int v, level;
}ver_t;

const int maxn = 1001;
int n, l, k;
vector<ver_t > graph[maxn];
vector<int > query;
bool inq[maxn];

int bfs(int s) {
	queue<ver_t > q;
	ver_t tmp;
	tmp.level = 0;
	tmp.v = s;
	q.push(tmp);
	inq[s] = true;
	int num = 0;
	while (!q.empty()) {
		ver_t front = q.front();
		q.pop();

		for (int i = 0; i < (int)graph[front.v].size(); ++i) {
			ver_t nxt = graph[front.v][i];
			nxt.level = front.level + 1;
			if (nxt.level > l)    break;

			if (!inq[nxt.v]) {
				q.push(nxt);
				inq[nxt.v] = true;
				num++;
			}
		}
	}

	return num;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> l;
	for (int i = 1; i <= n; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int tmp;
			cin >> tmp;
			ver_t ver;
			ver.v = i; ver.level = 0;
			graph[tmp].push_back(ver);
		}
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int tmp;
		cin >> tmp;
		query.push_back(tmp);
	}

	/* 2. MAIN LOGIC */
	for (int i = 0; i < k; ++i) {
		memset(inq, false, sizeof(inq));

		/* 3. OUTPUT MODULE */
		cout << bfs(query[i]) << endl;
	}

	return 0;
}