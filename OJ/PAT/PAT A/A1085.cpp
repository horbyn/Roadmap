#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int n;
long long p, a[maxn];//因为单个元素最大10^9, 而 m * p 则可能超过 10^9

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> p;
	for (int i = 0; i < n; ++i)    cin >> a[i];

	/* 2. MAIN LOGIC */
	int num = 0;
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		int tmp = 1, j = i + 1;
		for (; j < n; ++j) {
			if (a[j] <= a[i] * p)    tmp++;
			else    break;
		}
		if (tmp > num)    num = tmp;
		if (j == n)    break;//如果 j 遍历到边界(数组递增)那么后面都只会更小, 所以没必要遍历了
	}

	/* 3. OUTPUT MODULE */
	cout << num;

	return 0;
}