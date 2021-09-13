#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 20;
string z;
int n;
vector<int > rem;

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		/* 2. MAIN LOGIC */
		cin >> z;
		int dividend = atoi(z.c_str());
		int pivot = (int)z.size() / 2;
		int a = dividend;

		int b1 = 0;
		rem.clear();
		for (int i = 0; i < pivot; ++i) {
			rem.push_back(dividend % 10);
			b1 = (dividend /= 10);
		}
		int b2 = 0;
		for (int i = (int)rem.size() - 1; i >= 0; --i)
			b2 = b2 * 10 + rem[i];

		/* 3. OUTPUT MODULE */
		int b = b1 * b2;
		if (b == 0)    cout << "No\n";//划分出来的两个数乘积有可能是 0, 要特判
		else if (a % b == 0)    cout << "Yes\n";
		else    cout << "No\n";
	}

	return 0;
}