#include <iostream>
using namespace std;

const int maxn = 1000000;
int m, n;
bool non_prime[maxn], hash_table[maxn];

/* 哈希函数 */
int h(int k) {
	int idx = k % m;
	if (!hash_table[idx]) {
		hash_table[idx] = true;
		return idx;
	} else {//二次探测法解决冲突
		int sign = 1;
		for (int i = 1; i <= m / 2; ++i) {
			idx = (idx + (i * i * sign)) % m;
			sign = -sign;

			if (!hash_table[idx]) {
				hash_table[idx] = true;
				return idx;
			}
		}
	}
	return -1;
}

int main() {
	/* 0. INITIALIZATION */
	//初始化素数表
	for (int i = 2; i < maxn; ++i) {//10^4 个素数遍历范围是 10^6(见 B1013)
		if (non_prime[i] == false) {
			for (int j = i + i; j < maxn; j += i)    non_prime[j] = true;
		}
	}

	/* 1. INPUT MODULE */
	cin >> m >> n;
	if (non_prime[m])//如果 m 是非素数——即不是素数
		while (non_prime[++m]);//re-size 表长
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		/* 2. MAIN LOGIC */
		int ret = h(x);
		
		/* 3. OUTPUT LOGIC */
		if (ret == -1)    cout << "-";
		else    cout << ret;
		if (i != n - 1)    cout << " ";
	}

	return 0;
}