/* PA 19/25 */
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 10000;
int n, q;
int father[maxn];
bool isRoot[maxn];
vector<int > query[maxn];

int find_father(int x) {
	int a = x;
	while (x != father[x])    x = father[x];

	while (father[a] != a) {
		int fa = father[a];
		father[a] = x;
		a = fa;
	}

	return x;
}

void merge(int a, int b) {
	int x = find_father(a);
	int y = find_father(b);
	if (x != y)    father[y] = x;
}

int main() {
	/* 0. INITIALIZATION */
	for (int i = 0; i < maxn; ++i)    father[i] = i;

	/* 1. INPUT MODULE */
	int birds_num = -1;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num, root;
		cin >> num;
		for (int j = 0; j < num; ++j) {
			int inp;
			cin >> inp;
			if (birds_num < inp)    birds_num = inp;//编号最大的就是鸟的数量
			if (j == 0)    root = inp;//第一个输入作为集合的根
			else    merge(root, inp);//之后的输入都合并到根
		}
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		query[i].push_back(a);
		query[i].push_back(b);
	}

	/* 2. MAIN LOGIC */
	int trees_num = 0;
	for (int i = 1; i <= birds_num; ++i)    isRoot[find_father(i)] = true;
	for (int i = 1; i <= birds_num; ++i)
		if (isRoot[i] == true)    trees_num++;

	/* 3. OUTPUT MODULE */
	cout << trees_num << " " << birds_num << endl;
	for (int i = 0; i < q; ++i) {
		int fa = find_father(query[i][0]);
		int fb = find_father(query[i][1]);
		if (fa == fb)    cout << "Yes\n";
		else    cout << "No\n";
	}

	return 0;
}