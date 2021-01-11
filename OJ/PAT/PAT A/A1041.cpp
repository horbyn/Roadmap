#include <iostream>
using namespace std;

struct hash_t {
	int cou = 0;	//count
	int idx = -1;	//index
}has[10001];

int main() {
	int n, tmp, min = 100100, idx = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		has[tmp].cou++;
		if (has[tmp].cou > 1)    has[tmp].idx = -1;
		else    has[tmp].idx = i;
	}
	for (int i = 0; i < 10001; ++i) {
		if (min > has[i].idx && has[i].idx >= 0) {
			min = has[i].idx;
			idx = i;
		}
	}
	if (min == 100100)    cout << "None";
	else    cout << idx;

	return 0;
}#include <iostream>
using namespace std;

struct hash_t {
	int cou = 0;	//count
	int idx = -1;	//index
}has[10001];

int main() {
	int n, tmp, min = 100100, idx = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		has[tmp].cou++;
		if (has[tmp].cou > 1)    has[tmp].idx = -1;
		else    has[tmp].idx = i;
	}
	for (int i = 0; i < 10001; ++i) {
		if (min > has[i].idx && has[i].idx >= 0) {
			min = has[i].idx;
			idx = i;
		}
	}
	if (min == 100100)    cout << "None";
	else    cout << idx;

	return 0;
}