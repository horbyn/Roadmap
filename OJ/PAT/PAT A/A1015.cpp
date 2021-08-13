#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 100000;
int n, d;
bool prime[maxn];
vector<int > num;

/* 根据进制 d 反转数值 m: 除基取余法 */
void reverse(int m, int d) {
	num.clear();

	while (m) {
		int rem = m % d;
		num.push_back(rem);
		m /= d;
	}
}

/* 将 d 进制转化为十进制 */
int trans_decimal(int d) {
	int m = 0;
	for (int i = 0; i < (int)num.size(); ++i)
		m = m * d + num[i];
	return m;
}

int main() {
	/* 0. INITIALIZATION */
	memset(prime, true, sizeof(prime));
	for (int i = 2; i < maxn; ++i) {//初始化素数表
		if (prime[i]) {
			for (int j = i + i; j < maxn; j += i)    prime[j] = false;
		}
	}

	/* 1. INPUT MODULE */
	cin >> n;
	while (n > 0) {
		cin >> d;
		
		/* 2. MAIN LOGIC */
		reverse(n, d);
		int rev = trans_decimal(d);

		/* 3. OUTPUT MODULE */
		//只有当输入的 n 和反转的 rev 均为素数才输出 Yes
		if (prime[n] && prime[rev])    cout << "Yes\n";
		else    cout << "No\n";

		cin >> n;
	}

	return 0;
}