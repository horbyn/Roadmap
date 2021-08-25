#include <cstdio>
#include <queue>
#pragma warning(disable: 4996)
using namespace std;

const int maxn = 20, maxk = 1001;
int m, n, k, q;
int process[maxk], query[maxk], leave[maxk];
queue<int > que[maxn];

int main() {
	/* 1. INPUT MODULE */
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= k; ++i)    scanf("%d", &process[i]);
	for (int i = 0; i < q; ++i)    scanf("%d", &query[i]);

	/* 2. MAIN LOGIC */
	//初始化: 1 号和 2 号客户入队
	que[0].push(1); que[1].push(2);
	leave[1] = 480 + process[1]; leave[2] = 480 + process[2];
	int ptr = 2;
	for (int t = 480; t <= 1020; ++t) {//480 = 8 * 60; 1020 = 17 * 60
		//到时间出队
		for (int i = 0; i < n; ++i) {
			if (!que[i].empty()) {
				int leave_time = leave[que[i].front()];
				if (leave_time == t) {
					que[i].pop();
					if (!que[i].empty()) {
						int cur = que[i].front();
						leave[cur] = t + process[cur];
					}
				}
			}
		}

		//检查队列并入满队
		for (int i = 0; i < n; ++i)
			while (ptr < k && (int)que[i].size() < m)    que[i].push(++ptr);
	}

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < q; ++i) {
		if (leave[query[i]] <= 1020)    printf("%02d:%02d\n", leave[query[i]] / 60, leave[query[i]] % 60);
		else    printf("Sorry\n");
	}

	return 0;
}