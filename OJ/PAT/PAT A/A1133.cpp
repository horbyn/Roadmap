#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)//VS 使用 scanf() 要忽略警告
using namespace std;

typedef struct node_t {
	int data, next;
}node_t;

typedef struct list_t {
	list_t() { addr = prior = idx = 0; }

	int addr, prior, idx;//prior: 负数=3, k以内=2, k以外=1
}list_t;

const int maxn = 100000;
int n, k;
node_t node[maxn];
vector<list_t > list;

/* 比较函数 */
bool cmp(list_t a, list_t b) {
	if (a.prior != b.prior)    return a.prior > b.prior;
	else    return a.idx < b.idx;
}

int main() {
	/* 1. INPUT MODULE */
	int base;
	scanf("%d%d%d", &base, &n, &k);
	for (int i = 0; i < n; ++i) {
		int idx;
		scanf("%d", &idx);
		scanf("%d%d", &node[idx].data, &node[idx].next);
	}

	/* 2. MAIN LOGIC */
	//先提取到顺序表, 再直接对顺序表排序
	for (int i = base, num = 0; i != -1; i = node[i].next, ++num) {
		list_t tmp;
		tmp.addr = i;
		tmp.idx = num;
		if (node[i].data < 0)    tmp.prior = 3;
		else if (node[i].data <= k)    tmp.prior = 2;
		else    tmp.prior = 1;
		list.emplace_back(tmp);
	}
	sort(list.begin(), list.end(), cmp);

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < (int)list.size(); ++i) {
		int idx = list[i].addr;
		printf("%05d %d ", idx, node[idx].data);
		if (i == (int)list.size() - 1)    printf("-1\n");
		else    printf("%05d\n", list[i + 1].addr);
	}
	return 0;
}