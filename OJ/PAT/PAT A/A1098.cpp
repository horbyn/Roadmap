/*
 * 一些说明：
 * 排序第一句判断 if (i != 2 && is_same_arr(len)) 如果写成
 * if (is_same_arr(len))，则测试点三会不通过
 *
 * 原因是初始数组不算那个 partial 数组，也是就是如果给出
 * 初始数组 4 3 2 1；partial 数组也是 4 3 2 1，
 * 实际上只往下迭代一次是不行的
 */
#include <iostream>
#include <algorithm>
using namespace std;

static const int maxn = 128;
static int ori[maxn], mid[maxn], a[maxn];
static bool flag = false;

static bool is_same_arr(int len) {
	for (int i = 1; i <= len; ++i) {
		if (a[i] != mid[i])    return false;
	}
	return true;
}

static void down_adjust(int low, int high) {
	int i = low, j;
	while (2 * i <= high) {
		j = 2 * i;
		if (j + 1 <= high && a[j] < a[j + 1])    j++;
		if (a[i] < a[j])    swap(a[i], a[j]);
		i = j;
	}
}

static void create_heap(int len) {
	for (int i = len / 2; i >= 1; --i)
		down_adjust(i, len);
}

static void heap_sort(int len) {
	create_heap(len);
	for (int i = len; i > 2; --i) {
		if (i != 2 && is_same_arr(len))    flag = true;

		swap(a[1], a[i]);
		down_adjust(1, i - 1);//最后一轮比较第一个和第二个元素即可

		if (flag)    return;
	}
}

static void insertion_sort(int len) {
	for (int i = 2; i <= len; ++i) {
		if (i != 2 && is_same_arr(len))    flag = true;

		int swap = a[i], j;
		for (j = i; j > 1 && a[j - 1] > swap; --j)
			a[j] = a[j - 1];
		a[j] = swap;

		if (flag)    return;
	}
}

int main() {
	int n;

	/* 1. 输入 */
	cin >> n;
	for (int i = 1; i <= n; ++i)    cin >> ori[i];
	for (int i = 1; i <= n; ++i)    cin >> mid[i];

	/* 2. 主逻辑 && 输出 */
	for (int i = 1; i <= n; ++i)    a[i] = ori[i];
	heap_sort(n);
	if (flag) {
		cout << "Heap Sort\n" << a[1];
		for (int i = 2; i <= n; ++i)    cout << " " << a[i];
		return 0;
	}
	for (int i = 1; i <= n; ++i)    a[i] = ori[i];
	insertion_sort(n);
	cout << "Insertion Sort\n" << a[1];
	for (int i = 2; i <= n; ++i)    cout << " " << a[i];

	return 0;
}