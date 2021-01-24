#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static const int stu_has_max = 26 * 26 * 26 * 10;
static vector<vector<int> > stu(stu_has_max);

static int has_val(char s[], int n) {//hash value
	int sum = 0;
	for (int i = 0; i < n - 1; ++i)
		sum = sum * 26 + (s[i] - 'A');
	sum = sum * 10 + (s[n - 1] - '0');
	return sum;
}

int main() {
	int n, k;

	//1. INPUT, EXECUTE--TO RECORD STU QUERY
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int cou, num;//course
		char tmp[5];
		scanf("%d%d", &cou, &num);
		for (int j = 0; j < num; ++j) {//这门课有多少人报名
			scanf("%s", tmp);
			int idx = has_val(tmp, 4);
			stu[idx].push_back(cou);//按哪个学生保存当前课程
		}
	}
	
	//2. OUTPUT
	char tmp[5];
	for (int i = 0; i < n; ++i) {
		scanf("%s", tmp);
		int idx = has_val(tmp, 4);//是哪个学生
		printf("%s %d", tmp, stu[idx].size());
		sort(stu[idx].begin(), stu[idx].end());
		for (unsigned int j = 0; j < stu[idx].size(); ++j)
			printf(" %d", stu[idx][j]);
		printf("\n");
	}

	return 0;
}