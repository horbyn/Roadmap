#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 学生记录结构体 */
typedef struct student_t {
	int ge, gi, gf;
	int id, rank;//学生序号, 学生排名
	vector<int > pre;//学生志愿
}stu_t;

/* 学校录取结果结构体 */
typedef struct school_t {
	vector<int > admit;//录取结果: 保存学生序号
	int pre_rank;//上一个录取学生的排名: 因为排名相同时就算超出名额也要录取
}sch_t;

const int maxn = 40000;
int n, m, k;
int quota[maxn];
sch_t school[maxn];
stu_t stu[maxn];

/* 比较函数 */
bool cmp(stu_t a, stu_t b) {
	if (a.gf != b.gf)    return a.gf > b.gf;
	else    return a.ge > b.ge;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)    cin >> quota[i];
	for (int i = 0; i < n; ++i) {
		cin >> stu[i].ge >> stu[i].gi;
		stu[i].gf = (stu[i].ge + stu[i].gi) / 2;//计算总分
		stu[i].id = i;							//保存学生 id

		for (int j = 0; j < k; ++j) {
			int inp;
			cin >> inp;
			stu[i].pre.push_back(inp);
		}
	}

	/* 2. MAIN LOGIC */
	sort(stu, stu + n, cmp);//按成绩排序
	//更新排名
	stu[0].rank = 1;
	for (int i = 1; i < n; ++i) {
		if (stu[i].gf != stu[i - 1].gf)    stu[i].rank = i + 1;
		else if (stu[i].ge != stu[i - 1].ge)    stu[i].rank = i + 1;
		else    stu[i].rank = stu[i - 1].rank;
	}
	//择优录取
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int choice = stu[i].pre[j];
			//若学校名额足够 || 学校录取最低排名与当前这个学生的排名相同
			if (school[choice].admit.size() < quota[choice] ||
				school[choice].pre_rank == stu[i].rank) {
				school[choice].admit.push_back(stu[i].id);
				school[choice].pre_rank = stu[i].rank;
				break;//录取了就退出, 不然会出现一个学生被录取了好几次
			}
		}
	}

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < m; ++i) {
		sort(school[i].admit.begin(), school[i].admit.end());//输出要求升序
		if (!school[i].admit.empty()) {
			cout << school[i].admit[0];
			for (int j = 1; j < (int)school[i].admit.size(); ++j)    cout << " " << school[i].admit[j];
		}
		cout << endl;
	}
	return 0;
}