#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 10000;
int n, m, k;
unordered_map<int, vector<int > > mp;
vector<int > query[maxn];

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int g1, g2;
		cin >> g1 >> g2;
		if (mp.find(g1) == mp.end()) {
			vector<int > tmp;
			tmp.push_back(g2);
			mp[g1] = tmp;
		} else    mp[g1].push_back(g2);
	}
	for (int i = 0; i < m; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int tmp;
			cin >> tmp;
			query[i].push_back(tmp);
		}
	}

	/* 2. MAIN LOGIC */
	for (int i = 0; i < m; ++i) {
		bool flag = false;
		for (int j = 0; j < (int)query[i].size(); ++j) {
			int good = query[i][j];

			if (mp.find(good) == mp.end())    continue;
			else {
				for (int k = 0; k < (int)mp[good].size() && !flag; ++k) {
					int incomp = mp[good][k];

					for (int l = 0; l < (int)query[i].size() && !flag; ++l) {
						if (query[i][l] == good)    continue;//跳过自己

						if (query[i][l] == incomp)    flag = true;
					}
				}
			}

			if (flag)    break;
		}

		/* 3. OUTPUT MODULE */
		if (flag)    cout << "No\n";//不兼容->不能在一起->No
		else    cout << "Yes\n";
	}

	return 0;
}