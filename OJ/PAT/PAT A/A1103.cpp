#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxFactor = -1, k, n, p;
vector<int> temp;
vector<int> ans;

void DFS(int factor, int sumNum, int sumPower, int sumFactor) {
    //找到出口
	if (sumNum == k && sumPower == n) {//基本条件
		if (sumFactor > maxFactor) {//不唯一条件
			maxFactor = sumFactor;
			ans = temp;
		}
		return;
	}
    //死胡同
	if (factor <= 0 || sumNum >= k || sumPower > n)   return;

    //岔路口
	int power = (int)(pow((double)factor, (double)p));
	if (sumPower + power <= n) {//剪枝，然后才决定选不选当前这个数
		temp.push_back(factor);
		DFS(factor, sumNum + 1, sumPower + power, sumFactor + factor);
		temp.pop_back();
	}
	DFS(factor - 1, sumNum, sumPower, sumFactor);//不选当前这个数
}

int main() {
	cin >> n >> k >> p;

	DFS((int)sqrt((double)n), 0, 0, 0);

	if (ans.empty())    cout << "Impossible\n";
	else {
		cout << n << " = " << ans[0] << "^" << p;
		for (int i = 1; i < k; ++i)
			cout << " + " << ans[i] << "^" << p;
		cout << endl;
	}

	return 0;
}