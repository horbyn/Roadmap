/* 两个集合的关联: 同一幅图的即为同一个集合 */
#include <iostream>
using namespace std;

const int maxn = 10001;
int n, k, q;
int birds[maxn], father[maxn];
bool vis[maxn];
int query[maxn][2];

int find_father(int x) {
	int backup = x;

	while (x != father[x])    x = father[x];

	while (backup != x) {
		int backup_father = father[backup];
		father[backup] = x;
		backup = backup_father;
	}

	return x;
}

void unite(int a, int b) {
	int x = find_father(a);
	int y = find_father(b);
	if (x != y)    father[y] = x;
}

int main() {
	/* 0. INITIALIZATION */
	for (int i = 0; i < maxn; ++i)    father[i] = i;

	/* 1. INPUT MODULE */
	int bird_num = -1;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int tmp;
			cin >> tmp;
			if (bird_num < tmp)    bird_num = tmp;

			if (birds[tmp] == 0)    birds[tmp] = i;
			unite(find_father(birds[tmp]), i);
		}
	}
	cin >> q;
	for (int i = 0; i < q; ++i)    cin >> query[i][0] >> query[i][1];

	/* 2. MAIN LOGIC */
	for (int i = 1; i <= n; ++i)    vis[find_father(i)] = true;
	int set_num = 0;
	for (int i = 1; i <= n; ++i)
		if (vis[i] == true)    set_num++;

	/* 3. OUTPUT MODULE */
	cout << set_num << " " << bird_num << endl;
	for (int i = 0; i < q; ++i) {
		int b1 = query[i][0], b2 = query[i][1];
		int x = find_father(birds[b1]), y = find_father(birds[b2]);
		if (x != y)    cout << "No\n";
		else    cout << "Yes\n";
	}

	return 0;
}