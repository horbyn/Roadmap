#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

typedef struct man_t {
	int id, vir, tel, total, type;
}man_t;

const int maxn = 100000;
int n, l, h;
man_t man[maxn];

/* 比较函数 */
bool cmp(man_t a, man_t b) {
	if (a.type != b.type)    return a.type > b.type;//按司马光规则排序
	else if (a.total != b.total)    return a.total > b.total;//都是一类人则按总分排序
	else if (a.vir != b.vir)    return a.vir > b.vir;//总分相同按美德分排序
	else    return a.id < b.id;//美德分相同按 id 排序
}

/* 判断一个人类型 */
int judge_man(int v, int t) {
	if (t >= h && v >= h)    return 4;//圣人
	else if (t < h && v >= h)    return 3;//君子
	else if (t < h && v < h && v >= t)    return 2;//愚人
	else    return 1;//小人
}

int main() {
	/* 1. INPUT MODULE */
	scanf("%d%d%d", &n, &l, &h);
	for (int i = 0; i < n; ++i) {
		int inp_id, inp_vir, inp_tel;
		scanf("%d%d%d", &inp_id, &inp_vir, &inp_tel);
		if (inp_vir >= l && inp_tel >= l) {
			man[i].id = inp_id;
			man[i].vir = inp_vir;
			man[i].tel = inp_tel;
			man[i].total = inp_vir + inp_tel;
			man[i].type = judge_man(inp_vir, inp_tel);
		} else {//对于分数均低于门槛 L 的直接过滤掉
			n--;
			i--;
		}
	}

	/* 2. MAIN LOGIC */
	sort(man, man + n, cmp);

	/* 3. OUTPUT MODULE */
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)    printf("%08d %d %d\n", man[i].id, man[i].vir, man[i].tel);

	return 0;
}