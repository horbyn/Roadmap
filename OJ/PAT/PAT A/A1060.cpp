#include <iostream>
#include <string>

using namespace std;
/* 
for (i = 0, it1、it2; i < n; ++i) {
if (有'.'吗)
	{记录 poi}
if (有'有效位'吗)
	{记录 dig}
if (d1 或 d2)/if (*it 只有一个存在时)
	{存映像}
else    {找另一个 d}
if (n 满)
	if (有 poi 也有 dig) {退出}
	else if (有 poi 无 dig) {可以确定是0}
	else if (有 dig 无 poi) {遍历至 str.size()}
}

if (dig < poi)    {exp = poi - dig}
else if (poi < dig)    {exp = (dig - 1) - poi}

if (dig 都是 -1，即两个都是 0)    {相等，并输出}
else if (两个 exp 相等)    {按相等格式输出}
else    {按不相等格式输出}
*/

void print_float(string s, int n, int d, bool f, int e) {
	// 0.(从 d 开始的 n 位有效位) * 10 ^ (指数)
	// 小数点在前面要打印负号
	string::iterator it = s.begin() + d;
	char c = (char)('0' + e);
	int i;

	cout << "0.";
	for (i = 0; i < n || it != s.end(); ++i, ++it)    cout << *it;
	if (it == s.end() && i < n)
		while (i < n)    { cout << '0'; ++i }
	cout << "*10^";
	if (f)    cout << "-";
	cout << c;
}

int main() {
	int n;
	string s1, s2;
	string::iterator it1, it2;
	int poi1, poi2, dig1, dig2;///point, digit

	cin >> n >> s1 >> s2;
	it1 = s1.begin(); it2 = s2.begin();

	/* 寻找有效位与小数点 */
	dig1 = dig2 = poi1 = poi2 = 0;//初始化小数点、有效位位置
	int cou;
	bool flg1 = false, flg2 = false;//flag 标识是否已遇上第一个非零数值
	for (cou = 0; cou < n || it1 == s1.end() || it2 == s2.end(); ++it1, ++it2) {
		if (*it1 != '.')   ++poi1;//记录小数点位置
		if (!flg1 && (*it1 == '0' || *it1 == '.'))    ++dig1;//记录第一个非零数值位置
		else    flg1 = true;
		if (*it2 != '.')    ++poi2;
		if (!flg2 && (*it2 == '0' || *it2 == '.'))    ++dig2;
		else    flg2 = true;
			
		if (*it1 != '0' && *it2 != '0') {//当且仅当两串都遇上第一个有效数字时才开始记数
			//存映像(其实好像不用)
			++cou;
		} else if (*it1 != '0' && *it2 == '0') {
			//dig2 遍历至第一个非零值
			while (*it2 == '0')    { ++it2; ++dig2; }
			flg2 = true;
			++cou;
		} else if (*it2 != '0' && *it1 == '0') {
			//dig1 遍历至第一个非零值
			while (*it1 == '0')    { ++it1; ++dig1; }
			flg1 = true;
			++cou;
		}
	}
	//if (cou == n || it1 == s1.end() || it2 == s2.end()) {//退出时是否已知两串小数点, 以及有效位的位置?
		//if (有 poi 也有 dig)    {退出}
		//else if (有 poi 无 dig)    {可以确定是 0}
		//else if (有 dig 无 poi)    {遍历至 str.size()}
		/*if (poi1 && poi2 && dig1 && dig2);
		else if (!flg1 && !flg2);//确定是0,按相等格式输出
		else if ((flg1 && !flg2) || (flg2 && !flg1));//其中一个是零, 按不相等格式输出
		else if (poi1 == -1);//遍历 s1 至 str.size() 去找小数点
		else if (poi2 == -1);//遍历 s1 至 str.size() 去找小数点*/
	//退出时未遍历完两串就继续遍历
	if (it1 != s1.end() || it2 != s2.end()) {
		for (; it1 != s1.end(); ++it1) {
			if (*it1 != '.')    ++poi1;
			if (!flg1 && (*it1 == '0' || *it1 == '.'))    ++dig1;
			else    flg1 = true;
		}
		for (; it2 != s2.end(); ++it2) {
			if (*it2 != '.')    ++poi2;
			if (!flg2 && (*it2 == '0' || *it2 == '.'))    ++dig2;
			else    flg2 = true;
		}
	}

	/* 计算指数 */
	int exp1, exp2;//exponent
	if (dig1 < poi1)    exp1 = poi1 - dig1;
	else    exp1 = (dig1 - 1) - poi1;
	if (dig2 < poi2)    exp2 = poi2 - dig2;
	else    exp2 = (dig2 - 1) - poi2;

	string s0;
	for (ing j = 0; j < n; ++j)    s0.insert(j, 1, '0');
	if (!flg1 && !flg2) {//全零
		//针对全零的情况如00.0 和 000000 的考虑
		///按相等格式输出
		print_float(s0, n, 0, false, n);
		cout << endl;
	} else if (!flg1 && flg2) {// s1 是 0, s2 不是 0
		///按不相等格式输出
		print_float(s0, n, 0, false, n);
		cout << " ";
		if (poi2 + 1 < dig2)    print_float(s2, n, dig2, true, exp2);//小数点在有效数前面
		else    print_float(s2, n, dig2, false, exp2);
	} else if (flg1 && !flg2) {// s1 不是 0, s2 是 0
		///按不相等格式输出
	}

	if (exp1 == exp2);//按相等格式输出
	else;//按不相等格式输出

	return 0;
}
