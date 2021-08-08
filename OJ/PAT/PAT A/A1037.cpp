#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int nc, np;
int coupon[maxn], product[maxn];
int main() {
	/* 1. INPUT MODULE */
	cin >> nc;
	for (int i = 0; i < nc; ++i)    cin >> coupon[i];
	cin >> np;
	for (int i = 0; i < np; ++i)    cin >> product[i];

	/* 2. MAIN LOGIC */
	sort(coupon, coupon + nc);
	sort(product, product + np);
	int max = 0;
	int i = nc - 1, j = np - 1;
	while (i >= 0 && j >= 0) {//正数
		if (coupon[i] < 0 || product[j] < 0)    break;
		max += coupon[i--] * product[j--];
	}
	i = 0; j = 0;
	while (i < nc && j < np) {//负数
		if (coupon[i] >= 0 || product[j] >= 0)    break;
		max += coupon[i++] * product[j++];
	}

	/* 3. OUTPUT MODULE */
	cout << max;

	return 0;
}