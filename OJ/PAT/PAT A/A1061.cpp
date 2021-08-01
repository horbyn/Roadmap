/* PA 18/20 */
#include <iostream>
#include <string>
using namespace std;

/* 星期判断规则: A-Z */
bool is_date(char c) {
	if ('A' <= c && c <= 'G')    return true;
	else    return false;
}

/* 小时判断规则: 0-9或A-N */
bool is_hour(char c) {
	if (('0' <= c && c <= '9') || ('A' <= c && c <= 'N'))    return true;
	else    return false;
}

/* 分钟判断规则: a-z */
bool is_min(char c) {
	if ('a' <= c && c <= 'z')    return true;
	else    return false;
}

/* 星期转换 */
string date_trans(int d) {
	switch (d) {
	case 0: return "MON";
	case 1: return "TUE";
	case 2: return "WED";
	case 3: return "THU";
	case 4: return "FRI";
	case 5: return "SAT";
	case 6: return "SUN";
	default: return string("");
	}
}

int main() {
	/* 1. INPUT MODULE */
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;

	/* 2. MAIN LOGIC */
	int len1 = s1.size() < s2.size() ? s1.size() : s2.size();
	int day = -1, hour = -1;
	for (int i = 0; i < len1; ++i) {
		if (day != -1 && hour != -1)    break;
		
		if (s1[i] == s2[i]) {
			//第一个 share 代表星期几
			if (day == -1 && is_date(s1[i])) {
				day = (int)(s1[i] - 'A');
				continue;
			}
			//第二个 share 代表小时
			if (day != -1 && hour == -1 && is_hour(s1[i])) {//第一个 share 找到了
				if ('0' <= s1[i] && s1[i] <= '9')    hour = (int)(s1[i] - '0');
				else    hour = (int)(s1[i] - 'A') + 10;
			}
		}
	}
	int len2 = s3.size() < s4.size() ? s3.size() : s4.size();
	int min = -1;
	for (int i = 0; i < len2; ++i) {
		if (min != -1)    break;

		//第三个 share 代表分钟
		if (s3[i] == s4[i] && is_min(s3[i]))    min = i;
	}

	/* 3. OUTPUT MODULE */
	cout << date_trans(day) << " ";
	if (hour <= 9)    cout << "0" << hour << ":";//相当于printf(%02d)
	else    cout << hour << ":";
	if (min <= 9)    cout << "0" << min;//相当于printf(%02d)
	else    cout << min;

	return 0;
}