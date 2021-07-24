#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct student_t {
	string id, school;
	int score;
}stu_t;

typedef struct school_t {
	school_t() {//定义局部变量的结构体要初始化
		this->name = string("");
		this->rank = 0;
		this->weight = 0;
		this->num = 0;
		memset(this->score, 0, sizeof(this->score));
	}

	string name;
	int rank, weight, num, score[3];
}sch_t;

const int maxn = 100000;
int n;
stu_t stu[maxn];
vector<sch_t > sch;
map<string, int > s2i;

/* 判断函数一: 学生排序 */
bool cmp1(stu_t a, stu_t b) {
	return a.school < b.school;
}

/* 判断函数二: 学校按权重排序 */
bool cmp2(sch_t a, sch_t b) {
	return a.weight > b.weight;
}

/* 判断函数三: 学校按 PAT 规则排序 */
bool cmp3(sch_t a, sch_t b) {
	if (a.rank != b.rank)    return a.rank < b.rank;
	else if (a.num != b.num)    return a.num < b.num;
	else    return a.name < b.name;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	if (n == 0)    return 0;
	for (int i = 0; i < n; ++i) {
		cin >> stu[i].id >> stu[i].score >> stu[i].school;
		for (int j = 0; j < (int)stu[i].school.size(); ++j)    stu[i].school[j] |= 0x20;//学校转为小写
	}

	/* 2. MAIN LOGIC */
	//遍历每个学生, 取出成绩放入学校
	sort(stu, stu + n, cmp1);
	int school_idx = 0;
	for (int i = 0; i < n; ++i) {
		map<string, int >::iterator it = s2i.find(stu[i].school);

		if (it == s2i.end()) {
			s2i[stu[i].school] = school_idx++;

			sch_t tmp;
			tmp.name = stu[i].school;
			tmp.num++;
			if (stu[i].id[0] == 'B')    tmp.score[0] += (int)(stu[i].score / 1.5);
			else if (stu[i].id[0] == 'A')    tmp.score[1] += stu[i].score;
			else    tmp.score[2] += (int)(stu[i].score * 1.5);
			sch.push_back(tmp);
		}
		else {
			int idx = s2i[stu[i].school];
			sch[idx].num++;
			if (stu[i].id[0] == 'B')    sch[idx].score[0] += (int)(stu[i].score / 1.5);
			else if (stu[i].id[0] == 'A')    sch[idx].score[1] += stu[i].score;
			else    sch[idx].score[2] += (int)(stu[i].score * 1.5);
		}
	}
	//学校按权重排序
	for (int i = 0; i < (int)sch.size(); ++i)    sch[i].weight = sch[i].score[0] + sch[i].score[1] + sch[i].score[2];
	sort(sch.begin(), sch.end(), cmp2);
	//处理排名
	sch[0].rank = 1;
	for (int i = 1; i < (int)sch.size(); ++i) {
		if (sch[i].weight == sch[i - 1].weight)    sch[i].rank = sch[i - 1].rank;
		else    sch[i].rank = i + 1;
	}
	//学校按 PAT 规则排序
	sort(sch.begin(), sch.end(), cmp3);

	/* 3. OUTPUT MODULE */
	cout << (int)sch.size() << endl;
	for (int i = 0; i < (int)sch.size(); ++i)    cout << sch[i].rank << " " << sch[i].name << " " << sch[i].weight << " " << sch[i].num << endl;

	return 0;
}