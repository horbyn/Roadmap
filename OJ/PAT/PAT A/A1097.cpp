#include <cstdio>
#include <cmath>
#include <vector>
#pragma warning(disable: 4996)//VS 使用 scanf() 要忽略警告
using namespace std;

typedef struct node_t {
	int addr, data, nxt;
}node_t;

const int maxn = 100000;
int n;
node_t inp[maxn];
vector<node_t > res, rem;//result 数组和 removal 数组
bool vis[maxn];

int main() {
	/* 1. INPUT MODULE */
	int base;
	scanf("%d%d", &base, &n);
	for (int i = 0; i < n; ++i) {
		int idx;
		scanf("%d", &idx);
		scanf("%d%d", &inp[idx].data, &inp[idx].nxt);
		inp[idx].addr = idx;
	}

	/* 2. MAIN LOGIC */
	for (int i = base; i != -1; i = inp[i].nxt) {
		int data = abs(inp[i].data);
		if (!vis[data]) {//用哈希记录出现过的元素数值
			vis[data] = true;
			res.push_back(inp[i]);
		} else    rem.push_back(inp[i]);
	}

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < (int)res.size(); ++i) {
		printf("%05d %d ", res[i].addr, res[i].data);
		if (i == (int)res.size() - 1)    printf("-1\n");
		else    printf("%05d\n", res[i + 1].addr);
	}
	for (int i = 0; i < (int)rem.size(); ++i) {
		printf("%05d %d ", rem[i].addr, rem[i].data);
		if (i == (int)rem.size() - 1)    printf("-1\n");
		else    printf("%05d\n", rem[i + 1].addr);
	}
	return 0;
}