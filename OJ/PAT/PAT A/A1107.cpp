#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static const int maxn = 1000;
static int hobbies[maxn] = { 0 }, father[maxn] = { 0 }, root[maxn] = { 0 };

static int find_father(int child) {
	while (father[child] != child) {
		child = father[child];
	}
	return child;
}

static void union_set(int a, int b) {
	int fa = find_father(a);
	int fb = find_father(b);
	if (fa != fb) {
		father[fa] = fb;
	}
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	for (int i = 0; i < maxn; ++i)    father[i] = i;

	/* 1. INPUT && EXECUTE */
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string cou;
		cin >> cou;
		cou.erase(cou.end() - 1);
		int m = atoi(cou.c_str()), x;
		for (int j = 0; j < m; ++j) {
			cin >> x;
			if (hobbies[x] == 0)    hobbies[x] = i;//爱好未属于其他人

			union_set(i, find_father(hobbies[x]));//合并这个人和拥有这项爱好的人
		}
	}

	/* 2. OUTPUT */
	for (int i = 1; i <= n; ++i) {
		int r = find_father(i);
		if (r == i)    root[i]++;
		else    root[r]++;
	}

	sort(root + 1, root + n + 1, cmp);
	int num = 0;
	for (int i = 1; i <= n && root[i] != 0; ++i, ++num);
	cout << num << endl << root[1];
	for (int i = 2; i <= num; ++i)    cout << " " << root[i];

	return 0;
}