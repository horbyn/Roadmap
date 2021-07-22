/* 超级大水题 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct record_t {
	string name, id;
	int grade;
}rec_t;

const int maxn = 100000;
int n;
rec_t rec[maxn];

bool cmp(rec_t a, rec_t b) {
	return a.grade > b.grade;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> rec[i].name >> rec[i].id >> rec[i].grade;
	int min, max;
	cin >> min >> max;

	/* 2. MAIN LOGIC */
	sort(rec, rec + n, cmp);

	/* 3. OUTPUT MODULE */
	int num = 0;
	for (int i = 0; i < n; ++i) {
		if (rec[i].grade >= min && rec[i].grade <= max) {
			num++;
			cout << rec[i].name << " " << rec[i].id << endl;
		}
	}
	if (num == 0)    cout << "NONE\n";

	return 0;
}