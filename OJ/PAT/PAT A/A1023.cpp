#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 21;
string str;
int appear_nums[10];
vector<int > num_double;

int main() {
	/* 1. INPUT MODULE */
	cin >> str;

	/* 2. MAIN LOGIC */
	int cf = 0;
	for (int i = (int)str.size() - 1; i >= 0; --i) {
		//记录每个数出现的次数
		int dig = str[i] - '0';
		appear_nums[dig]++;

		//double
		int twice = 2 * dig + cf;
		if (twice < 10) {
			num_double.push_back(twice);
			cf = 0;
		}
		else {
			num_double.push_back(twice % 10);
			cf = 1;
		}
	}
	if (cf == 1) {
		num_double.push_back(1);
		appear_nums[1]--;
	}
	//遍历 double 后的数每个数出现的次数
	for (int i = 0; i < (int)num_double.size(); ++i) {
		int dig = num_double[i];
		appear_nums[dig]--;
	}
	//遍历每个数码出现次数, 非零就不符合题意
	bool flag = true;
	for (int i = 0; i < 10 && flag; ++i) {
		if (appear_nums[i] != 0)    flag = false;
	}

	/* 3. OUTPUT MODULE */
	if (flag)    cout << "Yes\n";
	else    cout << "No\n";
	for (int i = (int)num_double.size() - 1; i >= 0; --i)    cout << num_double[i];

	return 0;
}