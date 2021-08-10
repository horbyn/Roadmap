/* PA 18/25
 * 思路: 将时间转为线性
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

typedef struct record_t {
	int arrive, end;
	double wait;
}rec_t;

const int maxn = 10000, maxk = 100;
int n, k;
rec_t rec[maxn];
int window[maxk];

bool cmp(rec_t a, rec_t b) {
	return a.arrive < b.arrive;
}

int main() {
	/* 1. INPUT MODULE */
	scanf("%d%d", &n, &k);
	int early_people = 0;
	for (int i = 0; i < n; ++i) {
		int h, m, s;
		scanf("%d:%d:%d%d", &h, &m, &s, &rec[i].end);
		rec[i].arrive = h * 60 * 60 + m * 60 + s;
		rec[i].end *= 60;//以秒为单位
		if (rec[i].arrive < 8 * 60 * 60) {
			rec[i].wait = (double)(8 * 60 * 60 - rec[i].arrive);
			early_people++;
		}
	}

	/* 2. MAIN LOGIC */
	memset(window, -1, sizeof(window));
	sort(rec, rec + n, cmp);
	double sum = 0.0;
	int i = 0;//i 标识当前遍历到第几个人
	for (; i < early_people && i < k; ++i) {
		window[i] = i;//很早就来排队的人, 可以在刚开门的时候就进入窗口
	}
	for (int t = 0; t < 17 * 60 * 60 - 8 * 60 * 60; ++t) {
		//检查是否有窗口可提供服务
		for (int j = 0; j < k; ++j) {
			int cur = window[j];

			if (cur != -1 && rec[cur].end == t) {//窗口的人到达服务结束时间
				sum += rec[cur].wait;
			}

			if (cur == -1 || rec[cur].end == t) {//窗口没人 或 窗口的人已服务完
				//检查当前时间是否有人到达
				if (rec[i].arrive <= t + 8 * 60 * 60) {
					rec[i].wait = (double)(t + 8 * 60 * 60 - rec[i].arrive);//等待时间
					window[j] = i;
					rec[i].end += t;//更新结束时间: 这个人的服务结束时间要加上当前时间
					++i;
				}
			}
		}
	}

	/* 3. OUTPUT MODULE */
	printf("%.1lf", sum / 60 / i);

	return 0;
}