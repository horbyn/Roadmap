/* 用随机选择算法反而超时？ */
#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

const int maxn = 100001;
int n, a[maxn];

/* 划分子序列: 使中间某个元素 pivot 总是大于等于左子列, 小于等于右子列 */
int partition(int l, int r) {
	int pivot = a[l];

	int i = l, j = r;
	while (i < j) {
		for (; i < j && a[j] > pivot; --j);
		for (; i < j && a[i] <= pivot; ++i);
		if (i != j)    swap(a[i], a[j]);
	}
	if (a[i] != pivot)    swap(a[i], a[l]);

	return i;
}

/* 随机选择算法 */
void random_select(int l, int r, int k) {
	if (l == r)    return;

	int pivot = partition(l, r);
	int m = pivot - l + 1;
	if (m == k)    return;
	else if (m > k)    random_select(l, pivot - 1, k);
	else    random_select(pivot + 1, r, k - m);
}

int main() {
	/* 1. INPUT MODULE */
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	/* 2. MAIN LOGIC */
	random_select(1, n, n / 2);
	int s1 = 0;
	for (int i = 1; i <= n / 2; ++i)    s1 += a[i];

	/* 3. OUTPUT MODULE */
	if (n % 2 == 0)    printf("0 ");
	else    printf("1 ");
	printf("%d", sum - s1 - s1);//sum - s1 = s2

	return 0;
}