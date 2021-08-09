#include <iostream>
#include <cmath>
using namespace std;

typedef struct fraction_t {
	long long up, down;
}fra_t;

fra_t f1, f2;

/* 求公约数 */
long long gcd(long long a, long long b) {
	if (b == 0)    return a;
	else    return gcd(b, a % b);
}

/* 分数化简 */
fra_t reduction(fra_t f) {
	//化简三原则
	if (f.down < 0) {//1. 负数统一用分子表示
		f.up = -f.up;
		f.down = -f.down;
	}

	if (f.up == 0 || f.down == 0) {//2. 分子或分母任一个是 0
		f.up = 0;
		f.down = 1;
	} else {//3. 约分
		long long common = gcd(abs(f.up), abs(f.down));
		f.up /= common;
		f.down /= common;
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

/* 分数减法 */
fra_t subtraction(fra_t a, fra_t b) {
	fra_t sub;
	sub.up = a.up * b.down - b.up * a.down;
	sub.down = a.down * b.down;
	return reduction(sub);
}

/* 分数乘法 */
fra_t production(fra_t a, fra_t b) {
	fra_t pro;
	pro.up = a.up * b.up;
	pro.down = a.down * b.down;
	return reduction(pro);
}

/* 分数除法 */
fra_t quotiention(fra_t a, fra_t b) {
	fra_t quo;
	quo.up = a.up * b.down;
	quo.down = a.down * b.up;
	return reduction(quo);
}

/* 打印分数 */
void print_frac(fra_t f) {
	f = reduction(f);

	if (f.up < 0)    cout << "(";

	if (f.down == 1)    cout << f.up;//整数或 0
	else if (abs(f.up) < abs(f.down))    cout << f.up << "/" << f.down;//真分数: 注意比较要用绝对值
	else    cout << f.up / f.down << " " << abs(f.up % f.down) << "/" << f.down;//假分数: 注意分子要用绝对值

	if (f.up < 0)    cout << ")";
}

int main() {
	/* 1. INPUT MODULE */
	char sign;
	cin >> f1.up >> sign >> f1.down >> f2.up >> sign >> f2.down;

	/* 2. MAIN LOGIC */
	for (int i = 0; i < 4; ++i) {
		/* 3. OUTPUT MODULE */
		print_frac(f1);
		
		if (i == 0) {
			cout << " + ";
			print_frac(f2);
			cout << " = ";
			print_frac(addition(f1, f2));
			cout << endl;
		} else if (i == 1) {
			cout << " - ";
			print_frac(f2);
			cout << " = ";
			print_frac(subtraction(f1, f2));
			cout << endl;
		} else if (i == 2) {
			cout << " * ";
			print_frac(f2);
			cout << " = ";
			print_frac(production(f1, f2));
			cout << endl;
		} else if (i == 3) {
			cout << " / ";
			if (f2.up != 0) {
				print_frac(f2);
				cout << " = ";
				print_frac(quotiention(f1, f2));
			} else    cout << "0 = Inf";
		}
	}

	return 0;
}