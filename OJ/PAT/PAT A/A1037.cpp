#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int cou[maxn], pro[maxn];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int Nc, Np;

	cin >> Nc;
	for (int i = 0; i < Nc; ++i)    cin >> cou[i];
	cin >> Np;
	for (int i = 0; i < Np; ++i)    cin >> pro[i];

	sort(cou, cou + Nc, cmp);
	sort(pro, pro + Np, cmp);

	//1. CALC POSITIVE
	int amo = 0;//amount
	int i = 0, j = 0;
	while (i < Nc && j < Np) {
		if (cou[i] > 0 && pro[j] > 0) {
			amo += cou[i++] * pro[j++];
		} else    break;
	}

	//2. STORAGE POS
	int dst_i, dst_j;
	while (i < Nc && cou[i] > 0)    ++i;
	while (j < Np && pro[j] > 0)    ++j;
	dst_i = i; i = Nc - 1;
	dst_j = j; j = Np - 1;

	//3. CALC NEGATIVE
	while (i >= dst_i && j >= dst_j) {
		amo += cou[i--] * pro[j--];
	}

	cout << amo;
	return 0;
}