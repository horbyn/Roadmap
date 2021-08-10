#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

typedef struct poly_t {
	int exp = -1;
	double coe;
}poly_t;

const int maxn = 2001;
int k;
vector<poly_t > inp[2];
poly_t poly[maxn];

bool cmp(poly_t a, poly_t b) {
	return a.exp > b.exp;
}

int main() {
	/* 1. INPUT MODULE */
	for (int i = 0; i < 2; ++i) {
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			poly_t tmp;
			scanf("%d%lf", &tmp.exp, &tmp.coe);
			inp[i].push_back(tmp);
		}
	}

	/* 2. MAIN LOGIC */
	for (int i = 0; i < (int)inp[0].size(); ++i) {
		for (int j = 0; j < (int)inp[1].size(); ++j) {
			int idx = inp[0][i].exp + inp[1][j].exp;//指数相加
			poly[idx].coe += inp[0][i].coe * inp[1][j].coe;//系数相乘, 再合并同类项
			if (poly[idx].coe != 0)    poly[idx].exp = idx;
			else    poly[idx].exp = -1;//系数为 0 的重新修改为 -1, 相当于一个标记
		}
	}
	sort(poly, poly + maxn, cmp);//按指数从大到小排列
	int num = 0;
	while (poly[num].exp != -1)    num++;//指数未赋值过说明系数是 0, 即不输出

	/* 3. OUTPUT MODULE */
	printf("%d", num);
	for (int i = 0; i < num; ++i)    printf(" %d %.1lf", poly[i].exp, poly[i].coe);

	return 0;
}