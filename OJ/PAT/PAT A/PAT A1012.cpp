/*写在前面：连做带改用时165min
 *第一个问题：第一次做编译无论clang还是g++都总是爆堆栈错误，现象是
 *    main()开头打断点单步调试就ERROR退出
 *搞了很久才知道：大空间变量不能定义在函数内——main()也是函数，而将
 *    stu[MAXSIZE]、ran[10000000][4]等大空间变量定义为全局，通过
 *第二个问题：输出时的找最小——用"擂台法"最简单，但没注意用临时变量
 *    一个个"尝试"遍历后续序列，导致该最小变量不断被改变
*/
#include <iostream>
#include <algorithm>

#define MAXSIZE 2001

using namespace std;

struct stu_t {
	int num;
	int gra[4];//[0]='A'; [1]='C'; [2]='M'; [3]='E'
};

int cou = 0;//当前排序的科目course
struct stu_t stu[MAXSIZE];
int tmp[MAXSIZE];
int ran[10000000][4] = { 0 };

bool cmp(struct stu_t a, struct stu_t b) {
	return a.gra[cou] > b.gra[cou];
}

int main() {
	int n, m, min, idx;

	cin >> n >> m;
	//1. 处理输入，同时计算平均分
	for (int i = 0; i < n; ++i) {
		cin >> stu[i].num >> stu[i].gra[1]
			>> stu[i].gra[2] >> stu[i].gra[3];

		stu[i].gra[0] = (stu[i].gra[1] + stu[i].gra[2]
			+ stu[i].gra[3]) / 3;
	}
	for (int i = 0; i < m; ++i)    cin >> tmp[i];

	//2. 外循环对每个科目排序，内循环记录该科目排名
	for (; cou < 4; ++cou) {
		sort(stu, stu + n, cmp);
		ran[stu[0].num][cou] = 1;
		for (int i = 1; i < n; ++i) {
			if (stu[i].gra[cou] == stu[i - 1].gra[cou])
				ran[stu[i].num][cou] = ran[stu[i - 1].num][cou];
			else    ran[stu[i].num][cou] = i + 1;
		}
	}

	//3. 输出：要先找当前学生排名最高的科目
	for (int i = 0; i < m; ++i) {
		if (!ran[tmp[i]][0])    cout << "N/A" << endl;
		else {
			min = ran[tmp[i]][0];
			idx = 0;
			for (int j = 0; j < 4; ++j) {
				if (min > ran[tmp[i]][j]) {
					min = ran[tmp[i]][j];
					idx = j;
				}
			}
			cout << min;
			if (idx == 0)    cout << " " << 'A' << endl;
			else if (idx == 1)    cout << " " << 'C' << endl;
			else if (idx == 2)    cout << " " << 'M' << endl;
			else if (idx == 3)    cout << " " << 'E' << endl;
		}
	}
}