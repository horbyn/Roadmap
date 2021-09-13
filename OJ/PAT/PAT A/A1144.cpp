#include <iostream>
#include <map>
using namespace std;

const int maxn = 100000;
int n;
map<int, bool > mp;

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		mp[tmp] = true;
	}

	/* 2. MAIN LOGIC */
	int cr = 1;
	//找第一个最小的正整数
	for (map<int, bool >::iterator it = mp.begin(); it != mp.end(); ++it) {
		if (it->first >= 0) {
			cr = it->first;
			break;
		}
	}
	//找第一个最小的没出现的正整数
	for (int i = 0; i < n; ++i) {
		if (mp.find(cr) != mp.end())    cr++;
		else    break;
	}

	/* 3. OUTPUT MODULE */
	cout << cr;

	return 0;
}