/* ERROR */
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

typedef struct record_t {
	int id, est, area;
}rec_t;

typedef struct father_t {
	int fa, flag;
}fat_t;

typedef struct outcome_t {
	int id, num;
	double aver_est, aver_area;
}out_t;

const int maxn = 10000;
int n;
fat_t father[maxn];
rec_t peo[maxn];
vector<rec_t > family[maxn];
map<int, int > func;
vector<out_t > out;

int find_father(int x) {
	int a = x;
	while (x != father[x].fa)    x = father[x].fa;

	while (a != father[a].fa) {
		int fa = father[a].fa;
		father[a].fa = x;
		a = fa;
	}

	return x;
}

void merge(int a, int b) {
	int x = find_father(a);
	int y = find_father(b);
	if (x != y)    father[y].fa = x;
}

bool cmp(out_t a, out_t b) {
	if (a.aver_area != b.aver_area)    return a.aver_area > b.aver_area;
	else    return a.id < b.id;
}

int main() {
	/* 0. INITIALIZATION */
	for (int i = 0; i < maxn; ++i) {
		father[i].fa = i;
		peo[i].id = i;
	}

	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int id1, id2, id3, num;
		cin >> id1 >> id2 >> id3 >> num;
		father[id1].flag = father[id2].flag = father[id3].flag = 1;
		merge(id1, id2);
		merge(id1, id3);

		for (int j = 0; j < num; ++j) {
			int inp;
			cin >> inp;
			father[inp].flag = 1;
			merge(id1, inp);
		}

		cin >> peo[id1].est >> peo[id1].area;
	}

	/* 2. MAIN LOGIC */
	int cr = 0;
	for (int i = 0; i < maxn; ++i) {
		if (father[i].flag == 1) {
			int root = father[i].fa;
			if (func.find(root) == func.end())    func[root] = cr++;
			family[func[root]].push_back(peo[i]);
		}
	}
	for (int i = 0; i < cr; ++i) {
		int id = 0x3fffffff, num = 0;
		int estate = 0, area = 0;
		for (int j = 0; j < (int)family[i].size(); ++j) {
			if (id > family[i][j].id)    id = family[i][j].id;

			num++;
			estate += family[i][j].est;
			area += family[i][j].area;
		}

		out_t tmp;
		tmp.id = id; tmp.num = num;
		tmp.aver_est = (double)estate / num;
		tmp.aver_area = (double)area / num;
		out.push_back(tmp);
	}
	sort(out.begin(), out.end(), cmp);

	/* 3. OUTPUT MODULE */
	cout << cr << endl;
	for (int i = 0; i < cr; ++i) {
		cout << out[i].id << " " << out[i].num << " ";
		printf("%.3lf %.3lf\n", out[i].aver_est, out[i].aver_area);
	}

	return 0;
}