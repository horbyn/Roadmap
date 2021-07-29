#include <iostream>
#include <string>
using namespace std;

int a, b;

int main() {
	/* 1. INPUT MODULE */
	cin >> a >> b;

	/* 2. MAIN LOGIC */
	string str("");
	int sum = a + b;
	bool flag = sum < 0 ? true : false;
	if (sum < 0)    sum = -sum;
	//处理低三位
	for (int i = 0; i < 3; ++i) {
		int rem = sum % 10;
		char ch = (char)(rem + '0');
		str = ch + str;
		sum /= 10;
		if (sum == 0)    break;//数值是 0 一定要退出！！
	}
	//处理更高位(如果有)
	int digit = 2;
	while (sum) {
		if (++digit == 3) {
			str = "," + str;
			digit = 0;
		}
		int rem = sum % 10;
		char ch = (char)(rem + '0');
		str = ch + str;
		sum /= 10;
	}

	/* 3. OUTPUT MODULE */
	if (flag)    cout << "-";
	cout << str;

	return 0;
}