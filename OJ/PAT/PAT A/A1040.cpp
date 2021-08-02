/* PA 17/25
 * 子问题:    前面的都对称, 那看看再左一个/两个/三个..以及再右一个/两个/三个..还对不对称
 * 边界:      从 a[1] 开始, 比较 a[0]a[1] 和 a[1]a[2] 是否对称
 * dp[] 含义: 截至至 a[i] 左跟右对称的长度(不对称就是0)
 */
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1000;
int dp[maxn];
string str;

int check(int i) {
	int num = 0;
	for (int j = 1; i - j >= 0 && i + j < (int)str.size(); ++j) {
		if (str[i - j] != str[i + j])    break;
		++num;
	}
	if (num)    num = num * 2 + 1;//num 只表示往左或往右最多可以走多少步
	return num;
}

int main() {
	/* 1. INPUT MODULE */
	getline(cin, str);

	/* 2. MAIN LOGIC */
	for (int i = 1; i < (int)str.size() - 1; ++i)    dp[i] = check(i);
	int max = 0;
	for (int i = 0; i < (int)str.size(); ++i) {
		if (dp[i] > dp[max])    max = i;
	}

	/* 3. OUTPUT MODULE */
	cout << dp[max];

	return 0;
}