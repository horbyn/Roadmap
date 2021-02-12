#include <iostream>
#include <iomanip>
using namespace std;

static const int maxn = 100000;

struct node_t {
	char cha;
	int next;
	bool flag = false;
}node[maxn];

int main() {
	int addr1, addr2, n;

	//1. INPUT
	cin >> addr1 >> addr2 >> n;
	int inp;
	for (int i = 0; i < n; ++i) {
		cin >> inp;
		cin >> node[inp].cha >> node[inp].next;
	}

	//2. EXECUTE
	int i = addr1;
	while (i != -1) {//遍历第一条链表，标记为 true
		node[i].flag = true;
		i = node[i].next;
	}
	i = addr2;
	while (i != -1) {//遍历第二条链表
		if (node[i].flag) {//遇到 true 标识，说明当前为所求
			cout << setw(5) << setfill('0') << i;
			return 0;
		}
		i = node[i].next;
	}
	cout << "-1";//否则遍历完第二条链，那就是没有共同 suffix

	return 0;
}