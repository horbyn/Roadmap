#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 100000;
int n;
int a[maxn];
long long sum, s1;

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	/* 2. MAIN LOGIC */
	sort(a, a + n);
	for (int i = 0; i < n / 2; ++i)    s1 += a[i];

	/* 3. OUTPUT MODULE */
	if (n % 2 == 0)    cout << "0 ";
	else    cout << "1 ";
	int s2 = sum - s1;
	cout << abs(s2 - s1);

	return 0;
}