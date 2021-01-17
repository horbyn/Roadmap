#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100001;
int arr[maxn], p;

int binary_search(int min, int lef, int rig) {
	int mid = lef;
	long long tmp = (long long)arr[min] * p;
	while (lef <= rig) {
		mid = (lef + rig) / 2;
		if (tmp >= arr[mid])    lef = mid + 1;
		else    rig = mid - 1;
	}

	return mid - min;
}

int main() {
	int n;

	cin >> n >> p;
	for (int i = 0; i < n; ++i)    cin >> arr[i];

	sort(arr, arr + n);
	int num = 1, tmp_num;
	for (int i = 0; i < n; ++i) {
		tmp_num = binary_search(i, i, n - 1);
		if (tmp_num > num)    num = tmp_num;
	}

	cout << num;

	return 0;
}