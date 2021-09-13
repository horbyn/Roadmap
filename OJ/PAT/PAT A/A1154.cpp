#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef struct vertex_t {
	int u, v;
}ver_t;

const int maxn = 10000;
int n, m, k;
vector<ver_t > graph;
vector<int > query;
set<int > st;

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		ver_t tmp;
		cin >> tmp.u >> tmp.v;
		graph.push_back(tmp);
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		st.clear();
		query.clear();
		for (int j = 0; j < n; ++j) {
			int tmp;
			cin >> tmp;
			query.push_back(tmp);
			st.insert(tmp);
		}

		/* 2. MAIN LOGIC */
		bool flag = false;
		for (int j = 0; j < m && !flag; ++j) {
			int u = graph[j].u, v = graph[j].v;
			if (query[u] == query[v])    flag = true;
		}

		/* 3. OUTPUT MODULE */
		if (flag)    cout << "No\n";
		else    cout << (int)st.size() << "-coloring\n";
	}

	return 0;
}