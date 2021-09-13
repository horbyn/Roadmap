#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef struct record_t {
	string id;
	int gp, gm, gf, g;
	bool flag;
}rec_t;

const int maxn = 100000;
int p, m, n;
unordered_map<string, int > mp;
rec_t stu[maxn];

bool cmp(rec_t a, rec_t b) {
	if (a.g != b.g)    return a.g > b.g;
	else    return a.id < b.id;
}

int main() {
	/* 0. INITIALIZATION */
	for (int i = 0; i < maxn; ++i)    stu[i].gf = stu[i].gm = stu[i].gp = -1;

	/* 1. INPUT MODULE */
	cin >> p >> m >> n;
	string name;
	int score, cr = 0;
	for (int i = 0; i < p; ++i) {
		cin >> name >> score;
		int idx;
		if (mp.find(name) == mp.end()) {
			idx = cr;
			mp[name] = cr++;
		} else    idx = mp[name];
		stu[idx].id = name;
		stu[idx].gp = score;
	}
	for (int i = 0; i < m; ++i) {
		cin >> name >> score;
		int idx;
		if (mp.find(name) == mp.end()) {
			idx = cr;
			mp[name] = cr++;
		} else    idx = mp[name];
		stu[idx].id = name;
		stu[idx].gm = score;
	}
	for (int i = 0; i < n; ++i) {
		cin >> name >> score;
		int idx;
		if (mp.find(name) == mp.end()) {
			idx = cr;
			mp[name] = cr++;
		} else    idx = mp[name];
		stu[idx].id = name;
		stu[idx].gf = score;
	}

	/* 2. MAIN LOGIC */
	for (int i = 0; i < cr; ++i) {
		if (stu[i].gm > stu[i].gf) {
			double sum = stu[i].gm * 0.4 + stu[i].gf * 0.6;
			stu[i].g = (int)(sum + 0.5);//四舍五入, 然后取整
		}
		else    stu[i].g = stu[i].gf;

		if (stu[i].gp >= 200 && stu[i].g >= 60)    stu[i].flag = 1;
	}
	sort(stu, stu + cr, cmp);

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < cr; ++i) {
		if (stu[i].flag == 1) {
			cout << stu[i].id << " " << stu[i].gp << " "
				<< stu[i].gm << " " << stu[i].gf << " "
				<< stu[i].g << endl;
		}
	}

	return 0;
}