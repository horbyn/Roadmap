#include <cstdio>
#include <iostream>
#include <string>
#pragma warning(disable: 4996)

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

int main() {
	int n, i;
	string s1, s2;
	string::iterator it1, it2;
	int poi1, poi2, dig1, dig2;//point, digit

	cin >> n >> s1 >> s2;
	it1 = s1.begin(); it2 = s2.begin();

	dig1 = dig2 = -1;//初始化
	poi1 = poi2 = -1;
	for (i = 0; i < n; ++i) {
		if (*it1 == '.')    poi1 = i;//记录小数点位置
		else if (*it1 != '0')    dig1 = i;//记录第一个非零数值位置
		if (*it2 == '.')    poi2 = i;
		else if (*it2 != '0')    dig2 = i;
			
		if (dig1 >= 0 && dig2 >= 0) {
			//存映像
		} else if (dig1 >= 0 && dig2 == -1) {
			//dig2 遍历至第一个非零值
		} else if (dig2 >= 0 && dig1 == -1) {
			//dig1 遍历至第一个非零值
		}

		++it1; ++it2;
	}
	if (i == n - 1) {
		//if (有 poi 也有 dig)    {退出}
		//else if (有 poi 无 dig)    {可以确定是 0}
		//else if (有 dig 无 poi)    {遍历至 str.size()}
		if (poi1 != -1 && poi2 != -1 && dig1 != -1 && dig2 != -1);
		else if (dig1 == -1 && dig2 != -1);//确定是0,按相等格式输出
		else if ((dig1 == -1 && dig2 != -1) ||
			(dig1 != -1 && dig2 == -1))//其中一个是零
			;//按不相等格式输出
		else if (poi1 == -1);//遍历 s1 至 str.size() 去找小数点
		else if (poi2 == -1);//遍历 s1 至 str.size() 去找小数点
	}

	int exp1, exp2;//exponent
	if (dig1 < poi1)    exp1 = poi1 - dig1;
	else    exp1 = (dig1 - 1) - poi1;
	if (dig2 < poi2)    exp2 = poi2 - dig2;
	else    exp2 = (dig2 - 1) - poi2;

	if (exp1 == exp2);//按相等格式输出
	else;//按不相等格式输出

	return 0;
}