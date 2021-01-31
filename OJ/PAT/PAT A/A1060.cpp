/*
for (遍历两串) {
    if (有'.'吗)    {记录 poi}
    if (有'有效位'吗)    {记录 dig}
    if (有一个串已遇到第一个有效位而另一个串还没有)
	    {找另一个串的有效位}
	
	if (两串均未找到有效位)    {继续遍历，继续找}
	else if (两串均找到有效位)    {保存映像}
	else if (一个找到有效位，另一个没有)    {保存找到有效位的串的映像}
}
while (两串是否未找完)    {继续找小数点、第一个有效位; 或保存有效位映像}
if (两串遍历完了还未找到小数点)    {小数点即末尾}

计算指数();

if (两串映像相等 && 指数相等)    {按相等格式输出}
else    {按不相等格式输出}
*/
#include <iostream>
#include <string>

using namespace std;

void print_float(string s, bool f, int e) {
	string::iterator it = s.begin();

	cout << "0.";
	for (; it != s.end(); ++it)    cout << *it;
	cout << "*10^";
	if (f)    cout << "-";
	cout << to_string(e);
}

int main() {
	int n;
	string s1, s2;
	string::iterator it1, it2;
	int poi1, poi2, dig1, dig2;///point, digit

	cin >> n >> s1 >> s2;
	it1 = s1.begin(); it2 = s2.begin();

	/* 1. 寻找第一个有效位与小数点，并且会保存从第一个有效位开始至 n 位有效数 */
	dig1 = dig2 = poi1 = poi2 = -1;//初始化小数点、有效位位置
	int cou, i, j;//i, j 遍历 s1, s2
	string img1, img2;
	for (cou = i = j = 0; cou < n && it1 != s1.end() && it2 != s2.end(); ++it1, ++it2, ++i, ++j) {
		if (*it1 == '.')   poi1 = i;//记录小数点位置
		else if (*it1 != '0' && dig1 == -1)    dig1 = i;//记录第一个非零数值位置
		if (*it2 == '.')    poi2 = j;
		else if (*it2 != '0' && dig2 == -1)    dig2 = j;

		if ((dig1 != -1 && dig2 == -1) ||
			(dig2 != -1 && dig1 == -1)) {//一个串已找到第一个有效数字，另一串没有
			if (*it1 == '0') {//dig1 遍历至第一个非零值
				for (; it1 != s1.end() - 1 && (*it1 == '0' || *it1 == '.'); ++it1, ++i);
				if (*it1 != '0' && *it1 != '.')    dig1 = i;
			} else if (*it2 == '0') {//dig2 遍历至第一个非零值
				for (; it2 != s2.end() - 1 && (*it2 == '0' || *it2 == '.'); ++it2, ++j);
				if (*it2 != '0' && *it2 != '.')    dig2 = j;
			}
		}

		if (dig1 == -1 && dig2 == -1)    continue;//两串都是零
		else if (dig1 != -1 && dig2 != -1) {//当且仅当两串都遇上有效数字时才开始记数
			++cou;
			if (*it1 != '.')    img1 = img1 + *it1;
			if (*it2 != '.')    img2 = img2 + *it2;
		} else if (dig1 == -1 || dig2 == -1) {//一个当前位有效而 另一个遍历到最后一位仍未找到有效数
			if (dig1 == -1)    img2 = img2 + *it2;
			else    img1 = img1 + *it1;
		}
	}
	if (it1 != s1.end() || it2 != s2.end()) {//对于未找完的串还需要判断是否已找到小数点、是否已找到第一个非零值、以及是否已保存 n 个有效值的映像
		for (; it1 != s1.end(); ++it1, ++i) {
			if (*it1 == '.')    poi1 = i;//找小数点
			else if (*it1 != '0' && dig1 == -1)    dig1 = i;//找第一个非零值
			else if (img1.size() < (unsigned)n)    img1 = img1 + *it1;//除去'.'以及第一个非零值，其他值都保存映像
		}
		for (; it2 != s2.end(); ++it2, ++j) {
			if (*it2 == '.')    poi2 = j;
			else if (*it2 != '0' && dig2 == -1)    dig2 = j;
			else if (img2.size() < (unsigned)n)    img2 = img2 + *it2;
		}
	}
	while (img1.size() < (unsigned)n)    img1 = img1 + '0';//不够的映像填'0'
	while (img2.size() < (unsigned)n)    img2 = img2 + '0';
	if (it1 == s1.end() && poi1 == -1)    poi1 = s1.size();//如果遍历完了都没有小数点，那小数点就在最后面
	if (it2 == s2.end() && poi2 == -1)    poi2 = s2.size();

	/* 2. 计算指数 */
	int exp1, exp2;//exponent
	if (dig1 == -1)    exp1 = 0;
	else {
		if (dig1 < poi1)    exp1 = poi1 - dig1;
		else    exp1 = (dig1 - 1) - poi1;
	}
	if (dig2 == -1)    exp2 = 0;
	else {
		if (dig2 < poi2)    exp2 = poi2 - dig2;
		else    exp2 = (dig2 - 1) - poi2;
	}

	bool n1 = false, n2 = false;//negative symbol
	if (poi1 + 1 < dig1)    n1 = true;// 小数点在前面要打印负号
	if (poi2 + 1 < dig2)    n2 = true;
	if (img1 == img2 && exp1 == exp2) {
		cout << "YES ";
		print_float(img1, n1, exp1);
	} else {
		cout << "NO ";
		print_float(img1, n1, exp1);
		cout << " ";
		print_float(img2, n2, exp2);
	}

	return 0;
}