#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef struct student_t {
	string id;
	int c, m, e, a;
	int rank[4];
}stu_t;

const int maxn = 2000;
int n, m;
stu_t stu[maxn];
map<string, int > ma;
string query[maxn];

bool cmpa(stu_t a, stu_t b) {
	return a.a > b.a;
}

bool cmpc(stu_t a, stu_t b) {
	return a.c > b.c;
}

bool cmpm(stu_t a, stu_t b) {
	return a.m > b.m;
}

bool cmpe(stu_t a, stu_t b) {
	return a.e > b.e;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> stu[i].id >> stu[i].c >> stu[i].m >> stu[i].e;
		double sum = (double)stu[i].c + stu[i].m + stu[i].e;
		stu[i].a = (int)(sum / 3 + 0.5);//四舍五入
	}
	for (int i = 0; i < m; ++i)    cin >> query[i];

	/* 2. MAIN LOGIC */
	//排序 A
	sort(stu, stu + n, cmpa);
	stu[0].rank[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (stu[i].a == stu[i - 1].a)    stu[i].rank[0] = stu[i - 1].rank[0];
		else    stu[i].rank[0] = i + 1;
	}
	//排序 C
	sort(stu, stu + n, cmpc);
	stu[0].rank[1] = 1;
	for (int i = 1; i < n; ++i) {
		if (stu[i].c == stu[i - 1].c)    stu[i].rank[1] = stu[i - 1].rank[1];
		else    stu[i].rank[1] = i + 1;
	}
	//排序 M
	sort(stu, stu + n, cmpm);
	stu[0].rank[2] = 1;
	for (int i = 1; i < n; ++i) {
		if (stu[i].m == stu[i - 1].m)    stu[i].rank[2] = stu[i - 1].rank[2];
		else    stu[i].rank[2] = i + 1;
	}
	//排序 E
	sort(stu, stu + n, cmpe);
	stu[0].rank[3] = 1;
	for (int i = 1; i < n; ++i) {
		if (stu[i].e == stu[i - 1].e)    stu[i].rank[3] = stu[i - 1].rank[3];
		else    stu[i].rank[3] = i + 1;
	}
	//排好序后建立映射
	for (int i = 0; i < n; ++i)    ma[stu[i].id] = i;

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < m; ++i) {
		if (ma.find(query[i]) == ma.end())    cout << "N/A\n";
		else {
			int idx = ma[query[i]];
			int best = 0, rank = stu[idx].rank[0];

			//找最好的科目
			for (int j = 1; j < 4; ++j) {
				if (rank > stu[idx].rank[j]) {
					rank = stu[idx].rank[j];
					best = j;
				}
			}

			//映射科目缩写
			string subject;
			switch (best) {
				case 0: subject = "A"; break;
				case 1: subject = "C"; break;
				case 2: subject = "M"; break;
				default: subject = "E"; break;
			}

			cout << rank << " " << subject << endl;
		}
	}

	return 0;
}