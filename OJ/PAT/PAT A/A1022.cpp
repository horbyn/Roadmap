#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	map<string, vector<string> > mp;

	//1. 保存书目
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string id, str, key_cac;//key cache
		for (int j = 1; j < 7; ++j) {
			if (j == 1)    { cin >> id; cin.ignore(); continue; }
			else if (j == 4)    getline(cin, key_cac);
			else    getline(cin, str);

			while (1) {
				if (j == 4) {
					int k = 0;
					for (; key_cac[k] != ' ' && k < (int)key_cac.size(); ++k);
					str = key_cac.substr(0, k);
					key_cac.erase(0, k + 1);//待删除字符串最多只能删除到字符串结尾，所以最后一个字符虽然没有空格，但最多只删除到字符串末尾
				}

				if (mp.find(str) == mp.end()) {//键 str 不存在
					vector<string> v;
					v.push_back(id);
					mp[str] = v;
				} else {//键 str 存在
					vector<string> v;
					map<string, vector<string> >::iterator mi;
					mi = mp.find(str);
					v = mi->second;
					v.push_back(id);
					mp[str] = v;
				}

				if (j == 4 && key_cac.size() != 0)    continue;
				else    break;
			}
		}
	}

	//2. 保存用户搜索词
	vector<string> vec_key;
	cin >> m;
	cin.ignore();
	for (int i = 0; i < m; ++i) {
		string str;
		getline(cin, str);
		vec_key.push_back(str);
	}

	//3. 打印
	for (int i = 0; i < m; ++i) {
		//分离关键词
		string key;
		int j = 0;
		for (; j < (int)vec_key[i].size(); ++j);
		key = vec_key[i].substr(3, j);
		map<string, vector<string> >::iterator mi;
		mi = mp.find(key);

		cout << vec_key[i] << endl;
		if (mi != mp.end()) {
			sort(mi->second.begin(), mi->second.end());
			for (vector<string>::iterator vi = mi->second.begin();
				vi != mi->second.end(); ++vi)
				cout << *vi << endl;
		} else {
			cout << "Not Found" << endl;
		}
	}

	return 0;
}