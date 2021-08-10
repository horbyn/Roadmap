#include <cstdio>
#include <vector>
#pragma warning(disable: 4996)
using namespace std;

typedef struct poly_t {
	int exp;
	double coe;
}poly_t;

const int maxn = 11;
int k;
vector<poly_t > poly[2];

int main() {
	/* 1. INPUT MODULE */
	for (int i = 0; i < 2; ++i) {
		scanf("%d", &k);
		poly_t inp;
		for (int j = 0; j < k; ++j) {
			scanf("%d%lf", &inp.exp, &inp.coe);
			poly[i].push_back(inp);
		}
	}

	/* 2. MAIN LOGIC */
	vector<poly_t > sum;
	int i = 0, j = 0;
	while (i < (int)poly[0].size() && j < (int)poly[1].size()) {
		poly_t tmp;

		if (poly[0][i].exp == poly[1][j].exp) {//指数相同
			tmp.exp = poly[0][i].exp;
			tmp.coe = poly[0][i].coe + poly[1][j].coe;
			if (tmp.coe != 0)    sum.push_back(tmp);//如果系数为 0 输出会 PA
			++i; ++j;
		}
		else {//指数不同
			if (poly[0][i].exp > poly[1][j].exp)    sum.push_back(poly[0][i++]);
			else    sum.push_back(poly[1][j++]);
		}
	}
	while (i < (int)poly[0].size())    sum.push_back(poly[0][i++]);
	while (j < (int)poly[1].size())    sum.push_back(poly[1][j++]);

	/* 3. OUTPUT MODULE */
	printf("%d", (int)sum.size());
	for (int i = 0; i < (int)sum.size(); ++i)    printf(" %d %.1lf", sum[i].exp, sum[i].coe);

	return 0;
}