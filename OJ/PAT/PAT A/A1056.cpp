#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct mice_t {
	int wei, idx, rank;
}mic_t;

const int maxn = 1000;
int np, ng;
mic_t mice[maxn];
int seq[maxn];
queue<int > que;
vector<int > out[maxn], tmp;

bool cmp(mic_t a, mic_t b) {
	return a.idx < b.idx;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> np >> ng;
	for (int i = 0; i < np; ++i) {
		cin >> mice[i].wei;
		mice[i].idx = i;
	}
	for (int i = 0; i < np; ++i)    cin >> seq[i];

	/* 2. MAIN LOGIC */
	//初始队列
	for (int i = 0; i < np; ++i)    que.push(seq[i]);
	//比试
	int ptr = -1;//指示输出数组
	while (que.size() != 1) {
		//初始化
		ptr++;
		int group = que.size() / ng;
		int last = ng, len = ng;
		if (que.size() % ng) {
			group++;
			last = que.size() % ng;
		}

		for (int i = 0; i < group; ++i) {
			if (i == group - 1)    len = last;
			tmp.clear();

			//组内比试: 挑出属于同一组的
			for (int j = 0; j < len; ++j) {
				tmp.push_back(que.front());
				que.pop();
			}

			//找最大
			int max = -1, max_idx = 0;
			for (int j = 0; j < (int)tmp.size(); ++j) {
				if (max < mice[tmp[j]].wei) {
					max = mice[tmp[j]].wei;
					max_idx = tmp[j];
				}
			}
			que.push(max_idx);//最大的重新入队
			for (int i = 0; i < (int)tmp.size(); ++i) {
				if (tmp[i] == max_idx)    continue;
				out[ptr].push_back(tmp[i]);//其余的进入输出数组
			}
		}
	}
	//遍历输出数组, 排名
	mice[que.front()].rank = 1;
	out[ptr + 1].push_back(que.front());
	for (int i = ptr, rank = 1; i >= 0; --i) {
		rank += out[i + 1].size();
		for (int j = 0; j < (int)out[i].size(); ++j)    mice[out[i][j]].rank = rank;
	}
	sort(mice, mice + np, cmp);//按序号排序

	/* 3. OUTPUT MODULE */
	cout << mice[0].rank;
	for (int i = 1; i < np; ++i)    cout << " " << mice[i].rank;

	return 0;
}