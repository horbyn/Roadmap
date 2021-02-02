#include <iostream>
#include <vector>
#include <stack>
using namespace std;

static int m, n, k;//m 栈容量, n 序列长度, k 序列个数

bool is_pop_seq(vector<int>& seq_pus, vector<int>& seq_pop) {
	stack<int> s;
	int ptr_pus = 0;//ptr_pus 从固定的入栈序列中取数
	int ptr_pop = 0;//ptu_pop 从出栈序列中取数

	while (s.size() <= (unsigned)m && ptr_pop < n) {
		if (s.empty())    s.push(seq_pus[ptr_pus++]);

		if (s.top() == seq_pop[ptr_pop]) {//栈顶元素等于出栈序列元素
			s.pop();
			ptr_pop++;
		} else {
			if (ptr_pus < n && s.size() < (unsigned)m) {
				s.push(seq_pus[ptr_pus++]);//入栈序列还有元素，则入栈该元素
			} else    return false;//栈顶元素不等于出栈序列元素，且入栈序列已全部入完
		}
	}
	if (s.size() == (unsigned)m)    return false;//退出是因为栈满则出栈序列错误
	else    return true;//否则栈空即为符合的出栈序列
}

int main() {
	cin >> m >> n >> k;

	vector<int> seq_pus;//入栈序列
	vector<vector<int> > seq_pop;//出栈序列
	int inp;
	for (int i = 1; i <= n; ++i)    seq_pus.push_back(i);
	for (int i = 0; i < k; ++i) {
		vector<int> tmp;
		for (int j = 0; j < n; ++j) {
			cin >> inp;
			tmp.push_back(inp);
		}
		seq_pop.push_back(tmp);
	}

	for (int i = 0; i < k; ++i) {
		if (is_pop_seq(seq_pus, seq_pop[i]))    cout << "YES\n";
		else    cout << "NO\n";
	}

	return 0;
}