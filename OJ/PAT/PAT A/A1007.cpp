/* PA 17/25
 * 子问题:    前面的子问题都是最大, 那看看再加一个元素还是不是最大
 * 边界:      从 a[0] 开始, a[0] 自己就知道自己一个最大
 * dp[] 含义: 截至至 a[i] 的这一段连续序列, 和最大
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int k;
int a[maxn], dp[maxn];

int main() {
	/* 1. INPUT MODULE */
	cin >> k;
	for (int i = 0; i < k; ++i)    cin >> a[i];

	/* 2. MIAN LOGIC */
	//dp[i] 表示截至到第 i 个元素的连续子序列最大: 用状态转移方程求得
	dp[0] = a[0];
	for (int i = 1; i < k; ++i)    dp[i] = max(a[i], dp[i - 1] + a[i]);
	//设最大的子序列结尾于 end 位置, 由于 dp[end] 表示截至第 end 个元素的连续子序列最大
	//    因此 dp[end] 也是 dp[] 中的最大值
	int end = 0;
	for (int i = 0; i < k; ++i) {//擂台法选最大
		if (dp[i] > dp[end])    end = i;
	}
	//找开始于哪个下标, 设该下标为 base
	//    通过状态转移方程可知, 最大的 dp[] 开始于以自己为 dp[i] 的下标(即 a[i] == dp[i])
	//    ————因为若加上当前元素还更小, 那最大子序列就是自己; 而加上当前元素更大, 那最大子
	//    序列就依赖于前面的元素。所以从结尾往前推找起始时, 若 (a[i] != dp[i]) 则说明依赖
	//    于前面的元素, 即仍要往前推。而最终推到某个元素 (a[i] != dp[i]) 就说明从这个地方
	//    出发到结尾处是一段连续的最大子序列
	int base = end;
	while (base >= 0 && dp[base] != a[base])    base--;//开头元素是自己

	/* 3. OUTPUT MODULE */
	if (dp[end] < 0)    cout << "0 " << a[0] << " " << a[k - 1];
	else    cout << dp[end] << " " << a[base] << " " << a[end];

	return 0;
}