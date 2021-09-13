/* N 选 K 问题 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 400;
int n, k, p;
int max_fac = -1;
int a[maxn];
vector<int > tmp, ans;

void dfs(int idx, int nowK, int sum, int fac) {
	/* 死胡同 */
	//临界条件
	if (idx <= 0 || nowK > k || sum > n)    return;
	//题目指标
	if (nowK == k && sum == n) {//K 个数满足 && 基础指标(累加和)满足
		if (max_fac < fac) {//第二个指标(质因子总和)
			max_fac = fac;
			ans = tmp;
		}
		else if (max_fac == fac) {//第三个指标(最大数列)
			bool flag = false;
			for (int i = 0; i < k; ++i) {
				if (tmp[i] != ans[i]) {//第一个不相等的元素开始比较, 大就是大, 小就是小
					if (tmp[i] > ans[i])    flag = true;
					break;
				}
			}
			if (flag)    ans = tmp;
		}
		return;
	}

	/* 岔道口 */
	if (sum + a[idx] <= n) {//剪枝
		tmp.push_back(idx);
		dfs(idx, nowK + 1, sum + a[idx], fac + idx);//选
		tmp.pop_back();
	}
	dfs(idx - 1, nowK, sum, fac);//不选
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> k >> p;
	int m = (int)sqrt(n);
	for (int i = 0; i <= m; ++i)    a[i] = (int)pow(i, p);

	/* 2. MIAN LOGIC */
	dfs(m, 0, 0, 0);

	/* 3. OUTPUT MODULE */
	if (ans.empty())    cout << "Impossible";
	else {
		cout << n << " = ";
		for (int i = 0; i < (int)ans.size(); ++i) {
			cout << ans[i] << "^" << p;
			if (i != (int)ans.size() - 1)    cout << " + ";
		}
	}

	return 0;
}