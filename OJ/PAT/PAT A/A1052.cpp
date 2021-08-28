#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node_t {
	int addr, key, next;
	int flag;
}node_t;

const int maxn = 100000;
int n;
node_t link[maxn];

bool cmp(node_t a, node_t b) {
	if (a.flag != b.flag)    return a.flag > b.flag;
	else    return a.key < b.key;
}

int main() {
	/* 1. INPUT MODULE */
	int base;
	cin >> n >> base;
	for (int i = 0; i < n; ++i) {
		int idx;
		cin >> idx;
		link[idx].addr = idx;
		cin >> link[idx].key >> link[idx].next;
	}

	/* 2. MAIN LOGIC */
	int num = 0;
	for (int i = base; i != -1; i = link[i].next) {
		num++;
		link[i].flag = 1;
	}
	sort(link, link + maxn, cmp);

	/* 3. OUTPUT MODULE */
	if (num == 0)    printf("0 -1\n");
	else {
		printf("%d %05d\n", num, link[0]);
		for (int i = 0; i < num; ++i) {
			printf("%05d %d ", link[i].addr, link[i].key);
			if (i == num - 1)    printf("-1\n");
			else    printf("%05d\n", link[i + 1].addr);
		}
	}

	return 0;
}