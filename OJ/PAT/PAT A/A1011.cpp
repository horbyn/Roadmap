#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)//VS 使用 scanf() 要忽略警告
using namespace std;

const int maxn = 3;
const double price = 2.0;
typedef struct odds_t {
	double odd;
	int flag;
}odds_t;

odds_t odds[maxn][maxn];

/* 比较函数 */
bool cmp(odds_t a, odds_t b) {
	return a.odd > b.odd;
}

int main() {
	/* 1. INPUT MODULE */
	for (int i = 0; i < maxn; ++i)
		for (int j = 0; j < maxn; ++j)    odds[i][j].flag = j;//结构体要建立映射
	for (int i = 0; i < maxn; ++i)
		scanf("%lf%lf%lf", &odds[i][0].odd, &odds[i][1].odd, &odds[i][2].odd);

	/* 2. MAIN LOGIC */
	double profit = 1.0;
	for (int i = 0; i < maxn; ++i) {
		sort(odds[i], odds[i] + maxn, cmp);
		if (odds[i][0].flag == 0)    printf("W ");
		else if (odds[i][0].flag == 1)    printf("T ");
		else    printf("L ");

		profit *= odds[i][0].odd;
	}

	/* 3. OUTPUT MODULE */
	printf("%.2lf\n", (profit * 0.65 - 1) * price);

	return 0;
}