#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int maxn = 1000;
static int grade[maxn] = { 0 };

static struct mice_t {
	int idx;
	int weight;
}mice[maxn];

static bool cmp(struct mice_t a, struct mice_t b) {
	return a.weight > b.weight;
}

int main() {
	int Np, Ng;

	//1. INPUT
	cin >> Np >> Ng;
	for (int i = 0; i < Np; ++i) {
		mice[i].idx = i;
		cin >> mice[i].weight;
	}
	vector<struct mice_t> init_order;
	int idx;
	for (int i = 0; i < Np; ++i) {
		cin >> idx;
		init_order.push_back(mice[idx]);
	}

	//2. EXECUTE
	int arr_rest_len = init_order.size();//数组剩余长度初始为全部
	vector<struct mice_t> tmp;//保存每个 match 输掉的 mice
	while (arr_rest_len != 1) {
		int group = 0, base = 0, end = 0;
		while (end < arr_rest_len) {//这个循环处理每一个 turn 的所有 match
			int step = (arr_rest_len - base) < Ng ? (arr_rest_len - base) : Ng;
			end += step;
			sort(init_order.begin() + base, init_order.begin() + end, cmp);//相当于选出最大值
			for (int i = base + 1; i < end; ++i)    tmp.push_back(init_order[i]);//除最大值外其他值都是输的，保存下来排名
			struct mice_t fatest_mouse = init_order[base];
			init_order[group++] = fatest_mouse;
			base = end;
		}
		for (vector<struct mice_t>::iterator vi = tmp.begin();
			vi != tmp.end(); ++vi)    grade[vi->idx] = group + 1;
		arr_rest_len = group;
		tmp.clear();
	}
	grade[init_order[0].idx] = 1;//最后退出循环时排第一的肯定是第一名

	//3. OUTPUT
	cout << grade[0];
	for (int i = 1; i < Np; ++i)    cout << " " << grade[i];

	return 0;
}