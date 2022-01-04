#include <iostream>
#include <string>
using namespace std;

int main() {
	//1. INPUT MODULE
	string sa(""), sb("");
	int a = 0, b = 0, c = 0;

	//2. MAIN MODULE
	cin >> sa >> sb;
	a = stoi(sa);
	b = stoi(sb);
	c = a + b;
	bool nega = false;
	if (c < 0) {
		c = -c;
		nega = true;
	}
	string sum = to_string(c);

	//3. OUTPUT MODULE
	if (sum.size() > 3)
		for (int i = sum.size() - 3; i > 0; i -= 3)
			sum.insert(i, string(","));
	if (nega)    cout << "-";
	cout << sum << endl;

	return 0;
}
