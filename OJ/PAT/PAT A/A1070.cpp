#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

typedef struct mooncake_t {
	double stock, price_unit, price_total;
}mc_t;

const int maxn = 1000;
int n, d;
mc_t moonc[maxn];

bool cmp(mc_t a, mc_t b) {
	return a.price_unit > b.price_unit;
}

int main() {
	/* 1. INPUT MODULE */
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i)    scanf("%lf", &moonc[i].stock);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &moonc[i].price_total);
		moonc[i].price_unit = moonc[i].price_total / moonc[i].stock;
	}

	/* 2. MAIN LOGIC */
	sort(moonc, moonc + n, cmp);
	double profit = 0.0;
	for (int i = 0; i < n && d; ++i) {
		if (moonc[i].stock <= d) {                      //够取
			d -= (int)moonc[i].stock;
			moonc[i].stock = 0;
			profit += moonc[i].price_total;
		} else {                                        //不够取
			double portion = (double)d / moonc[i].stock;
			moonc[i].stock -= (double)d;
			profit += portion * moonc[i].price_total;
			d = 0;
		}
	}

	/* 3. OUTPUT MODULE */
	printf("%.2lf", profit);

	return 0;
}