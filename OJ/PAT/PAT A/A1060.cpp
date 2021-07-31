#include <iostream>
#include <string>
using namespace std;

typedef struct dig_t {
	string sign;//有效数
	int dec, fst, exp;//小数点位置, 首个有效位, 指数
}dig_t;

int n;
dig_t a, b;

/* 初始化 */
void init() {
	a.exp = b.exp = n;//指数初始为 n
	for (int i = 0; i < n; ++i) {//有效数值初始为全 0
		a.sign += '0';
		b.sign += '0';
	}
}

/* 预处理: 主要是找小数点位置, 以及保存有效值 */
void pre_handle(string& s, dig_t& d) {
	d.dec = -1; d.fst = -1;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == '.')    d.dec = i;//保存小数点位置
		else if (s[i] != '0' && d.fst == -1) {
			d.fst = i;
			d.sign.clear();//若找到有一个有效值, 那就不是 0, 所以要先清空有效数值
		}

		if (d.fst != -1 && s[i] != '.')    d.sign += s[i];
	}
	if (d.dec == -1)    d.dec = (int)s.size();//如果遍历完成没见到小数点, 那就在最后
	while ((int)d.sign.size() < n)    d.sign += '0';//如果不够精度, 那就末尾补零
}

/* 判相等 */
bool judge_equal(int n) {
	if (a.fst == -1 || b.fst == -1) {//如果有一个数是 0
		if (a.fst == -1 && b.fst == -1)    return true;
		else    return false;
	}

	//计算指数: 正数=小数点位置-首位有效值位置; 负数=小数点位置-首位有效值位置+1
	a.exp = a.dec - a.fst; b.exp = b.dec - b.fst;
	if (a.exp < 0)    a.exp++;
	if (b.exp < 0)    b.exp++;
	if (a.exp != b.exp)    return false;//指数不相等

	//对比两个数的有效数值
	for (int i = 0; i < n; ++i) {
		if (a.sign[i] != b.sign[i])    return false;//有一个不相同就不相等
	}
	return true;
}

int main() {
	/* 1. INPUT MODULE */
	string s1, s2;
	cin >> n >> s1 >> s2;

	/* 2. MAIN LOGIC */
	init();
	pre_handle(s1, a);
	pre_handle(s2, b);

	/* 3. OUTPUT MODULE */
	if (judge_equal(n)) {
		cout << "YES 0.";
		for (int i = 0; i < n; ++i)    cout << a.sign[i];
		cout << "*10^" << a.exp;
	} else {
		cout << "NO 0.";
		for (int i = 0; i < n; ++i)    cout << a.sign[i];
		cout << "*10^" << a.exp;
		cout << " 0.";
		for (int i = 0; i < n; ++i)    cout << b.sign[i];
		cout << "*10^" << b.exp;
	}

	return 0;
}