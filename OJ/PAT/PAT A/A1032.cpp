#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

static const int maxn = 100000;
int node[maxn];

int cmp_lists(stack<int> ls1, stack<int> ls2) {
	int ret = -1, cou = 1;//count
	while (ls1.size() && ls2.size()) {//只有当两条链都有元素时才遍历
		if (ls1.top() != ls2.top()) {
			if (cou == 1)    return -1;
			else    break;
		} else {
			ret = ls1.top();//记录每次栈顶相等时的元素
			ls1.pop();
			ls2.pop();
		}
		cou++;
	}
	return ret;
}

int main() {
	int addr1, addr2, n;

	//1. INPUT
	cin >> addr1 >> addr2 >> n;
	int inp;
	char inp_ch;
	for (int i = 0; i < n; ++i) {
		cin >> inp;
		cin >> inp_ch >> node[inp];//每个 node[] 元素就是 next
	}

	//2. EXECUTE
	int idx = addr1;
	stack<int> list1;
	while (1) {//遍历第一条链，入栈沿途枚举的地址
		list1.push(idx);
		idx = node[idx];
		if (idx == -1)    break;
	}
	idx = addr2;
	stack<int> list2;
	while (1) {
		list2.push(idx);
		idx = node[idx];
		if (idx == -1)    break;
	}

	//3. OUTPUT
	int ret = cmp_lists(list1, list2);
	cout << ret;

	return 0;
}