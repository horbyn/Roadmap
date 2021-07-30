#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 100;
int num[maxn], num_rev[maxn], sum_tmp[maxn];

/* 交换 */
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/* 反转 */
void reverse(int a[], int n) {
	for (int i = 0; i < n / 2; ++i)
		swap(a[i], a[n - i - 1]);
}

/* 大数相加: 由于产生的进位会使数组长度加一, 所以用返回值表示是否需要为数组增加一位 */
bool add(int a[], int b[], int n) {
	int cf = 0;
	memset(sum_tmp, 0, sizeof(sum_tmp));

	for (int i = n - 1; i >= 0; --i) {//从最低位起, 分离每一位并累加
		int sum = a[i] + b[i] + cf;
		if (sum < 10) {
			cf = 0;
			sum_tmp[i] = sum;
		} else {//如果有进位只保留低位
			cf = 1;
			sum_tmp[i] = sum % 10;
		}
	}

	if (cf == 1) {//如果有进位整个数组后移一位, 开头保存进位 1
		for (int i = n - 1; i >= 0; --i)    sum_tmp[i + 1] = sum_tmp[i];
		sum_tmp[0] = 1;
		return true;
	} else    return false;
}

/* 判断是否 palin~ 数 */
bool is_palin(int a[], int n) {
	int num = 0;
	for (; num < n / 2; ++num)
		if (a[num] != a[n - num - 1])    break;

	if (num == n / 2)    return true;
	else    return false;
}

int main() {
	/* 1. INPUT MODULE */
	string str;
	int k;
	cin >> str >> k;

	/* 2. MAIN LOGIC */
	for (int i = 0; i < (int)str.size(); ++i)    num[i] = (int)(str[i] - '0');//转化为大数组织方式
	int cr = 0, len = (int)str.size();
	for (; cr < k; ++cr) {
		if (is_palin(num, len))    break;

		for (int i = 0; i < len; ++i)    num_rev[i] = num[i];
		reverse(num_rev, len);//反转
		if (add(num, num_rev, len))    len++;//按位累加
		for (int i = 0; i < len; ++i)    num[i] = sum_tmp[i];
	}

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < len; ++i)    cout << num[i];
	cout << "\n" << cr;

	return 0;
}