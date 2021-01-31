#include <iostream>
#include <string>
#include <map>
using namespace std;

bool is_alpha_cha(char c) {
	if ((c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9'))
		return true;
	else    return false;
}

int main() {
	string str;

	//1. INPUT
	getline(cin, str);

	//2. EXECUTE
	map<string, int> mp;
	string::iterator is = str.begin();
	string map_key;
	for (; is != str.end() - 1; ++is) {//由于需要检查当前字符的下一个字符，为了不越界，循环条件只进行到 end() - 1 就行了
		if (is_alpha_cha(*is)) {//当前字符是否是 alpha cha
			if (*is >= 'A' && *is <= 'Z')
				map_key = map_key + (char)(*is + 32);//大写要转换
			else    map_key = map_key + *is;
		} else    continue;//不是 alpha cha 的跳过

		if (!is_alpha_cha(*(is + 1))) {//下一个字符不是 alpha cha
			if (mp.find(map_key) == mp.end())    mp[map_key] = 1;//键在 map 中不存在，初始为 1
			else {
				int ori = mp[map_key];
				ori++;
				mp[map_key] = ori;//下标方式访问 map 会覆盖，所以先取出值自增，再放回去
			}
			map_key.clear();
		}
	}
	if (is == str.end() - 1) {//特列：一个字符的字符串
		map_key = map_key + *is;
		mp[map_key] = 1;
	}

	//3. OUTPUT: FIND OUT MAX
	string max_key;
	int max_val = -1;
	map<string, int>::iterator im = mp.begin();
	for (; im != mp.end(); ++im) {
		if (im->second > max_val) {// 擂台法找最值
			max_val = im->second;
			max_key = im->first;
		}
	}
	cout << max_key << " " << mp[max_key];
	return 0;
}