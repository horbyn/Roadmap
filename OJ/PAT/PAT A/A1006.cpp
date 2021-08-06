#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct record_t {
	string id;
	int in, out;
}rec_t;

const int maxn = 100000;
int m;
rec_t record[maxn];

/* 比较函数: 按开始时间从早到晚 */
bool cmp1(rec_t a, rec_t b) {
	return a.in < b.in;
}

/* 比较函数: 按离开时间从晚到早 */
bool cmp2(rec_t a, rec_t b) {
	return a.out > b.out;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> record[i].id;
		
		char discard;//接收":"
		int h1, m1, s1, h2, m2, s2;
		cin >> h1 >> discard >> m1 >> discard >> s1;
		cin >> h2 >> discard >> m2 >> discard >> s2;

		record[i].in = h1 * 3600 + m1 * 60 + s1;//时间处理核心: 将多维转化为一维
		record[i].out = h2 * 3600 + m2 * 60 + s2;
	}

	/* 2. MAIN LOGIC */
	sort(record, record + m, cmp1);
	cout << record[0].id << " ";
	sort(record, record + m, cmp2);
	cout << record[0].id;

	return 0;
}