#include <cstdio>//这道题用 cin 输入会超时
#include <cstring>
#include <algorithm>
#pragma warning(disable: 4996)//VS 使用 scanf() 要忽略警告
using namespace std;

typedef struct man_t {
	char name[16];
	int age, worth;
}man_t;

typedef struct query_t {
	int num, min, max;
}que_t;

const int maxn = 100000;
int n, k;
man_t man[maxn];
que_t query[maxn];

/* 比较函数 */
bool cmp(man_t a, man_t b) {
	if (a.worth != b.worth)    return a.worth > b.worth;
	else if (a.age != b.age)    return a.age < b.age;
	else    return strcmp(a.name, b.name) < 0;
}

int main() {
	/* 1. INPUT MODULE */
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)    scanf("%s%d%d", man[i].name, &man[i].age, &man[i].worth);
	for (int i = 0; i < k; ++i)    scanf("%d%d%d", &query[i].num, &query[i].min, &query[i].max);

	/* 2. MAIN LOGIC */
	//排序
	sort(man, man + n, cmp);
	//筛选范围
	for (int i = 0; i < k; ++i) {
		int num = query[i].num, min = query[i].min, max = query[i].max;

		/* 3. OUTPUT MODULE */
		printf("Case #%d:\n", i + 1);
		int k = 0;
		for (int j = 0; j < n && k < num; ++j) {
			if (min <= man[j].age && man[j].age <= max) {//符合这个范围的才给予输出
				k++;
				printf("%s %d %d\n", man[j].name, man[j].age, man[j].worth);
			}
		}
		if (k == 0)    printf("None\n");
	}

	return 0;
}