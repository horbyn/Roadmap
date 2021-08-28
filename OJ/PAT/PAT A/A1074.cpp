/* PA(18/25) */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct node_t {
	int addr, data, next;
}node_t;

const int maxn = 100000;
int n, k;
node_t link[maxn];
vector<node_t > rev;

void swap(node_t *a, node_t *b) {
	node_t* tmp = a;
	a = b;
	b = tmp;
}

int main() {
	/* 1. INPUT MODULE */
	int base;
	cin >> base >> n >> k;
	for (int i = 0; i < n; ++i) {
		int idx;
		cin >> idx;
		link[idx].addr = idx;
		cin >> link[idx].data >> link[idx].next;
	}

	/* 2. MAIN LOGIC */
	int num = 0;
	for (int i = base; i != -1; i = link[i].next) {
		num++;
		rev.push_back(link[i]);
	}
	for (int i = 0; i < n / k; ++i) {//整个链以 k 为组, 分为多少组就多少次外循环
		for (int j = 0; j < k / 2; ++j) {//组内以 k/2 为界一前一后交换即反转
			swap(rev[j], rev[k - j - 1]);
		}
	}

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < (int)rev.size(); ++i) {
		printf("%05d %d ", rev[i].addr, rev[i].data);
		if (i == (int)rev.size() - 1)    printf("-1\n");
		else    printf("%05d\n", rev[i + 1].addr);
	}

	return 0;
}