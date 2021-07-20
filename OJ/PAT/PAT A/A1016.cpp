#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

typedef struct record_t {
	string name;
	int mon, d, h, m;
	bool flag;
}record_t;

const int maxn = 1000;
int n, cost[24];
record_t rec[maxn];

/* 比较函数 */
bool cmp(record_t a, record_t b) {
	if (a.name != b.name)    return a.name < b.name;
	else if (a.mon != b.mon)    return a.mon < b.mon;
	else if (a.d != b.d)    return a.d < b.d;
	else if (a.h != b.h)    return a.h < b.h;
	else    return a.m < b.m;
}

int main() {
	/* 1. INPUT MODULE */
	for (int i = 0; i < 24; ++i)    scanf("%d", &cost[i]);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		string flag;
		cin >> rec[i].name;
		scanf("%d:%d:%d:%d", &rec[i].mon, &rec[i].d, &rec[i].h, &rec[i].m);
		cin >> flag;
		if (flag == "on-line")    rec[i].flag = true;
		else    rec[i].flag = false;
	}

	/* 2. MAIN LOGIC */
	sort(rec, rec + n, cmp);
	double charge = 0.0;
	string name = rec[0].name;
	cout << name;
	printf(" %02d\n", rec[0].mon);
	for (int i = 0; i < n; ++i) {
		int min = 0;
		double tmp_charge = 0.0;

		if (rec[i].flag && i + 1 < n && !rec[i + 1].flag) {
			if (name != rec[i].name) {
				printf("Total amount: $%.2lf\n", charge / 100.0);
				charge = 0.0;
			}

			int d = rec[i].d, h = rec[i].h, m = rec[i].m;

			//处理时间的逻辑: 核心思路就是拆成一分钟一分钟地去算
			for (; d <= rec[i + 1].d; ++d) {
				int end_h = d < rec[i + 1].d ? 23 : rec[i + 1].h;
				for (; h <= end_h; ++h) {
					int end_m;
					if (d == rec[i + 1].d)
						end_m = h < rec[i + 1].h ? 60 : rec[i + 1].m;
					else    end_m = 60;

					for (; m < end_m; ++m) {
						min++;
						tmp_charge += (double)cost[h];
					}
					m = 0;
				}
				h = 0;
			}
		} else    continue;
		charge += tmp_charge;

		/* 3. OUTPUT MODULE */
		if (name != rec[i].name) {
			name = rec[i].name;
			cout << name;
			printf(" %02d\n", rec[i].mon);
		}
		printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
			rec[i].d, rec[i].h, rec[i].m, rec[i + 1].d,
			rec[i + 1].h, rec[i + 1].m, min, tmp_charge / 100.0);
	}
	printf("Total amount: $%.2lf\n", charge / 100.0);

	return 0;
}