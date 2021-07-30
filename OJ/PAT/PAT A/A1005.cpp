#include <iostream>
#include <string>
using namespace std;

const int maxn = 1000;
int n;
int s[maxn];
string str;

string hash_trans(int v) {
	switch (v) {
	case 1: return "one";
	case 2: return "two";
	case 3: return "three";
	case 4: return "four";
	case 5: return "five";
	case 6: return "six";
	case 7: return "seven";
	case 8: return "eight";
	case 9: return "nine";
	default: return "zero";
	}
}

int main() {
	/* 1. INPUT MODULE */
	string inp;
	cin >> inp;//由于超过 int 范围所以用字符串接收

	/* 2. MAIN LOGIC */
	int sum = 0;
	for (int i = 0; i < (int)inp.size(); ++i)     sum += (int)(inp[i] - '0');//求出每位累加和
	while (sum) {//拆出累加和每一位
		int rem = sum % 10;
		str = " " + hash_trans(rem) + str;
		sum /= 10;
	}
	if (!str.empty())    str.erase(0, 1);
	else    str = hash_trans(0);//如果输入为 0, 需要特判

	/* 3. OUTPUT MODULE */
	cout << str;

	return 0;
}