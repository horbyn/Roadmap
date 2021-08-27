/* PA(15/25) */
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

typedef struct record_t {
	string name;
	int MM, dd, HH, mm, dura;
	bool flag;
}rec_t;

const int maxn = 1000;
int n;
int rate[24];
rec_t rec[maxn];

bool cmp(rec_t a, rec_t b) {
	if (a.name != b.name)    return a.name < b.name;
	else    return a.dura < b.dura;
}

int main() {
	/* 1. INPUT MODULE */
	for (int i = 0; i < 24; ++i)    scanf("%d", &rate[i]);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> rec[i].name;
		scanf("%d:%d:%d:%d", &rec[i].MM, &rec[i].dd, &rec[i].HH, &rec[i].mm);
		cin >> tmp;
		rec[i].dura = rec[i].dd * 1440 + rec[i].HH * 60 + rec[i].mm;//计算持续时间
		if (tmp == "on-line")    rec[i].flag = true;
		else    rec[i].flag = false;
	}

	/* 2. MAIN LOGIC */
	sort(rec, rec + n, cmp);
	double sum = 0.0;
	string cur = "";
	for (int i = 0; i < n; ++i) {
		if (rec[i].flag) {
			if (i + 1 < n && !rec[i + 1].flag) {//一条记录
				if (cur != rec[i].name) {//不是同一个人, 那就输出上一个人的总价
					if (i != 0) {
						printf("Total amount: $%.2lf\n", sum / 100.0);
						sum = 0.0;
					}
					cur = rec[i].name;
					cout << rec[i].name;
					printf(" %02d\n", rec[i].MM);
				}

				double tmp = 0.0;
				for (int t = rec[i].dura; t < rec[i + 1].dura; ++t) {//这对记录持续时间内的话费
					tmp += rate[t % 1440 / 60];
				}
				sum += tmp;

				/* 3. OUTPUT MODULE */
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
					rec[i].dd, rec[i].HH, rec[i].mm,
					rec[i + 1].dd, rec[i + 1].HH, rec[i + 1].mm,
					rec[i + 1].dura - rec[i].dura, tmp / 100.0);

				++i;
			}
		}
	}
	printf("Total amount: $%.2lf\n", sum / 100.0);

	return 0;
}