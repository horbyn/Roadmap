/* PA, 14/20
 * 考点: 大数乘法
 * 思路: 由于是重新排列, 所以排列后的数码出现次数, 必然和原数值的数码出现次数相等
 */
#include <iostream>
#include <string>
using namespace std;

const int maxn = 21;//最高位双倍后可能有进位, 所以多留出一个位置
int k;
int dig_ori[maxn], dig_dou[maxn];
int num_ori[10], num_dou[10];

int main() {
	/* 1. INPUT MODULE */
	string inp;
	cin >> inp;

	/* 2. MAIN LOGIC */
	//如果是负数, 摘掉负号
	bool nege = false;
	if (inp[0] == '-') {
		nege = true;
		inp.erase(0, 1);
	}
	//分离出每一位: 记录每个数码出现次数
	int len = (int)inp.size();
	for (int i = 0; i < len; ++i) {
		int dig = (int)(inp[i] - '0');//拆出每个数码
		dig_ori[i] = dig;
		num_ori[dig]++;//记录这个数码出现次数
	}
	//双倍: 并记录双倍后每个数码出现次数
	int cf = 0;//进位位
	for (int i = len - 1; i >= 0; --i) {
		int sum = 2 * dig_ori[i] + cf;//每个数位双倍
		if (sum < 10) {
			cf = 0;
			dig_dou[i] = sum;
			num_dou[sum]++;//记录数码出现次数
		} else {
			cf = 1;
			int low = sum % 10;
			dig_dou[i] = low;
			num_dou[low]++;//记录数码出现次数
		}
	}
	//比较两次数码出现次数
	int same = 0;
	for (; same < len; ++same) {
		if (num_ori[same] != num_dou[same])    break;
	}

	/* 3. OUTPUT MODULE */
	if (same == len)    cout << "Yes\n";
	else    cout << "No\n";
	if (nege)    cout << "-";
	if (cf == 1)    cout << "1";//如果最高位有进位
	for (int i = 0; i < len; ++i)    cout << dig_dou[i];

	return 0;
}