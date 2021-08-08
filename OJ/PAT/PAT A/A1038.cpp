/* PA 19/30 */
/* 思路: 1. 由于短串后面会续着长串, 因此短串末尾的'0'实质是长串开头的字符。
 *          所以只要将短串末尾第一个'0'改为其开头字符就行
 * PA思路: 1. 是不是需要保证每个数位都比前面的数位小, 这样才能保证连接后的所有串都是最小?
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct string_t {
	string str;
	int idx;
}str_t;

const int maxn = 10000;
int n;
vector<string > ori;
str_t str[maxn];

/* 排序: 按第一个字符的字典序排列, 若第一个字符相同则长串排前面 */
bool cmp1(str_t a, str_t b) {
	if (a.str[0] != b.str[0])    return a.str < b.str;
	else    return a.str.size() > b.str.size();
}

/* 排序: 按字典序排列 */
bool cmp2(str_t a, str_t b) {
	return a.str < b.str;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string inp;
		cin >> inp;
		//剔除开头的字符'0'
		int j = 0;
		while (inp[j] == '0' && j < (int)inp.size())    ++j;
		if (j != 0)    inp.erase(0, j);

		str[i].str = inp;
		str[i].idx = i;
		ori.push_back(inp);
	}

	/* 2. MAIN LOGIC */
	sort(str, str + n, cmp1);
	for (int i = 0; i < n; ++i) {
		int len = str[i].str.size();//遍历长度以最长的串为准
		char front = str[i].str[0];//记录每个串的开头字符

		for (int j = i + 1; j < n; ++j) {
			if (str[j].str[0] != front)    break;
			else    ++i;

			if ((int)str[j].str.size() < len)
				//找出第一个'0', 改为开头字符————即末尾追加一个开头字符
				str[j].str += front;
		}
	}
	sort(str, str + n, cmp2);

	/* 3. OUTPUT MODULE */
	for (int i = 0; i < n; ++i) {
		int idx = str[i].idx;
		cout << ori[idx];
	}

	return 0;
}