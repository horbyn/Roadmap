#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct data_t {
	string acc, pwd;

	data_t (string _acc, string _pwd) : acc(_acc), pwd(_pwd) {}
}data_t;

const int maxn = 1000;
int n;
vector<data_t > out;

int main() {
	/* 1. MAIN MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string acc, pwd;
		cin >> acc >> pwd;

		/* 2. MAIN LOGIC */
		bool change = false;
		for (int j = 0; j < (int)pwd.size(); ++j) {
			switch (pwd[j]) {
			case '1': pwd[j] = '@'; change = true; break;
			case '0': pwd[j] = '%'; change = true; break;
			case 'l': pwd[j] = 'L'; change = true; break;
			case 'O': pwd[j] = 'o'; change = true; break;
			default: break;
			}
		}

		if (change) {
			data_t tmp(acc, pwd);
			out.push_back(tmp);
		}
	}

	/* 3. OUTPUT MODULE */
	if (!out.empty()) {
		cout << (int)out.size() << endl;
		for (int i = 0; i < (int)out.size(); ++i)    cout << out[i].acc << " " << out[i].pwd << endl;
	}
	else {
		cout << "There is ";
		if (n)    cout << n << " accounts ";
		else    cout << "1 account ";
		cout << "and no account is modified";
	}
	return 0;
}