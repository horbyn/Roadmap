#include <iostream>
using namespace std;

const int maxn = 100;
int ini_arr[maxn];//initial array
int par_arr[maxn];//partial array
int sor_arr[maxn];//sorted array
int tmp[maxn];

void merge(int lef, int rig, int rig_end) {
	int k = lef, lef_end = rig - 1;
	int len = rig_end - lef + 1;
	while (lef <= lef_end && rig <= rig_end) {
		if (sor_arr[lef] < sor_arr[rig])
			tmp[k++] = sor_arr[lef++];
		else    tmp[k++] = sor_arr[rig++];
	}
	while (lef <= lef_end)    tmp[k++] = sor_arr[lef++];
	while (rig <= rig_end)    tmp[k++] = sor_arr[rig++];
    //以下注释的写法MSVC能通过，g++6.5不通过
	//for (k = 0; k < len; ++k, rig_end--)
    //  sor_arr[rig_end--] = tmp[rig_end];
	for (k = 0; k < len; ++k, rig_end--)
		sor_arr[rig_end] = tmp[rig_end];
}

int main() {
	int n, tmp_n;
	bool flg = false;

	cin >> n;
	tmp_n = n;
	for (int i = 0; i < n; ++i)    cin >> ini_arr[i];
	for (int i = 0; i < n; ++i)    cin >> par_arr[i];

	// INSEARTION SORT
	for (int i = 0; i < n; ++i)    sor_arr[i] = ini_arr[i];
	for (int i = 0; i < tmp_n - 1; ++i) {
		int swp = sor_arr[i + 1], j;
		for (j = i + 1; j > 0; --j) {
			if (sor_arr[j - 1] > swp)
				sor_arr[j] = sor_arr[j - 1];
			else    break;
		}
		sor_arr[j] = swp;

		if (!flg) {
			for (j = 0; j < tmp_n; ++j)
				if (par_arr[j] != sor_arr[j])    break;
			if (j == tmp_n) {
				cout << "Insertion Sort\n";
				tmp_n = i + 3;
				flg = true;
			}
		} else {
			flg = false;
			for (j = 0; j < n; ++j) {
				cout << sor_arr[j];
				if (j != n - 1)    cout << " ";
			}
		}
	}

	// MERGE SORT
	for (int i = 0; i < n; ++i)    sor_arr[i] = ini_arr[i];
	for (int stp = 1; stp < tmp_n; stp *= 2) {//step
		int i = 0;
		for (; i < n - 2 * stp; i += 2 * stp)
			merge(i, i + stp, i + 2 * stp - 1);
		if (i + stp < n)    merge(i, i + stp, n - 1);

		if (!flg) {
			for (i = 0; i < tmp_n; ++i)
				if (par_arr[i] != sor_arr[i])    break;
			if (i == tmp_n) {
				cout << "Merge Sort\n";
				tmp_n = 2 * stp + 1;
				flg = true;
			}
		} else {
			flg = false;
			for (i = 0; i < n; ++i) {
				cout << sor_arr[i];
				if (i != n - 1)    cout << " ";
			}
		}
	}

	return 0;
}