/* PA(20/25) */
/* 思路: 就是数偶数, 偶数=欧拉图; 两奇数=半欧拉图; 大于两奇数=非欧拉图 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 501;
int n, m;
vector<int > graph[maxn];
vector<int > degree;

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	/* 2. MAIN LOGIC */
	int odd_num = 0;
	for (int i = 1; i <= n; ++i) {
		int num = (int)graph[i].size();//数出度
		degree.push_back(num);
		if (num % 2 != 0)    odd_num++;
	}

	/* 3. OUTPUT MODULE */
	cout << degree[0];
	for (int i = 1; i < (int)degree.size(); ++i)    cout << " " << degree[i];
	if (odd_num == 0)    cout << "\nEulerian";
	else if (odd_num == 2)    cout << "\nSemi-Eulerian";
	else    cout << "\nNon-Eulerian";

	return 0;
}