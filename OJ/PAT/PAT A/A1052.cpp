#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)//VS 使用 scanf() 要忽略警告
using namespace std;

typedef struct node_t {
	int beg, key, nxt, flag;
}node_t;

const int maxn = 100000;
int n;
node_t node[maxn];

/* 比较函数 */
bool cmp(node_t a, node_t b) {
	if (a.flag != b.flag)    return a.flag > b.flag;
	else    return a.key < b.key;
}

int main() {
	/* 1. INPUT MODULE */
	int base;
	scanf("%d%d", &n, &base);
	for (int i = 0; i < n; ++i) {
		int idx;
		scanf("%d", &idx);
		node[idx].beg = idx;
		scanf("%d%d", &node[idx].key, &node[idx].nxt);
	}

	/* 2. MAIN LOGIC */
	for (int i = base; i != -1; i = node[i].nxt)    node[i].flag = 1;
	sort(node, node + maxn, cmp);
	for (int i = 0; i < n; ++i) {//重新组织链表关系
		if (i == n - 1)    node[i].nxt = -1;
		else    node[i].nxt = node[i + 1].beg;
	}

	/* 3. OUTPUT MODULE */
	printf("%d %05d\n", n, node[0].beg);
	for (int i = 0; i < n; ++i) {
		printf("%05d %d ", node[i].beg, node[i].key);
		if (i == n - 1)    printf("-1\n");
		else    printf("%05d\n", node[i].nxt);
	}

	return 0;
}