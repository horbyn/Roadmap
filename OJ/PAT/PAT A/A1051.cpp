#include <iostream>
#include <stack>
using namespace std;

const int maxn = 1000;
int m, n, k;
int seq[maxn][maxn];
stack<int > sta;

/* 判断序列是否是出栈序列 */
bool judge(int i) {
	while (!sta.empty())    sta.pop();//初始化栈

	int v = 1, j = 0;//v 指示入栈数值, j 指示序列当前元素
	sta.push(v++);
	while (!sta.empty()) {
		int top = sta.top();//获取栈顶数值
		if (top == seq[i][j]) {//若栈顶与序列元素相同
			sta.pop();
			j++;
			if (sta.empty()) {
				if (v != n + 1)    sta.push(v++);
				else    return true;
			}
		} else {//若栈顶与序列元素不同
			if (sta.size() == m)    return false;

			if (v != n + 1)    sta.push(v++);
			else    return false;
		}
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < n; ++j)
			cin >> seq[i][j];

	/* 2. MAIN LOGIC */
	for (int i = 0; i < k; ++i)
		/* 3. OUTPUT MODULE */
		if (judge(i))    cout << "YES\n";
		else    cout << "NO\n";

	return 0;
}