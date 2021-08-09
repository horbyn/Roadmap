#include <iostream>
#include <cmath>
using namespace std;

typedef struct fraction_t {
	long long up, down;
}fra_t;

const int maxn = 100000;
int n;
fra_t frac[maxn];

/* 求最大公约数 */
long long gcd(long long a, long long b) {
	if (b == 0)    return a;
	else    return gcd(b, a % b);
}

/* 化简 */
fra_t reduction(fra_t f) {
	//1. 由于题目限定了符号出现在最前面————即只有分子才带符号, 所以原则一满足
	if (f.down == 0) {//2. 分母为 0 则转化为分子为 0
		f.up = 0;
		f.down = 1;
	} else {//3. 约分
		long long result = gcd(abs(f.up), abs(f.down));
		f.up /= result;
		f.down /= result;
	}
	return f;
}

/* 分数加法 */
fra_t addition(fra_t a, fra_t b) {
	fra_t sum;

	sum.up = a.up * b.down + b.up * a.down;
	sum.down = a.down * b.down;

	return reduction(sum);
}

/* 打印分数 */
void print_frac(fra_t f) {
	f = reduction(f);

	if (f.down == 1)    cout << f.up;//整数或 0
	else if (abs(f.up) < abs(f.down))    cout << f.up << "/" << f.down;//真分数
	else    cout << f.up / f.down << " " << abs(f.up % f.down) << "/" << f.down;//假分数
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char sign;
		cin >> frac[i].up >> sign >> frac[i].down;
	}

	/* 2. MAIN LOGIC */
	fra_t sum = frac[0];
	for (int i = 1; i < n; ++i)    sum = addition(sum, frac[i]);

	/* 3. OUTPUT MODULE */
	print_frac(sum);

	return 0;
}