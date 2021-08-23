#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1001;
int n;
int father[maxn], isRoot[maxn];
int hobby[1001];

int find_father(int x) {
	int a = x;
	while (x != father[x])    x = father[x];

	while (a != father[a]) {
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

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	/* 0. INITIALIZATION */
	for (int i = 1; i < maxn; ++i)    father[i] = i;

	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string tmp;
		int num;
		cin >> num >> tmp;
		for (int j = 0; j < num; ++j) {
			int inp;
			cin >> inp;
			if (hobby[inp] == 0)    hobby[inp] = i;
			
			merge(find_father(hobby[inp]), i);
		}
	}

	/* 2. MAIN LOGIC */
	for (int i = 1; i <= n; ++i)    isRoot[find_father(i)]++;
	int num = 0;
	for (; isRoot[num + 1] != 0; ++num);
	sort(isRoot + 1, isRoot + num + 1, cmp);

	/* 3. OUTPUT MODULE */
	cout << num << endl << isRoot[1];
	for (int i = 2; i <= num; ++i)    cout << " " << isRoot[i];

	return 0;
}