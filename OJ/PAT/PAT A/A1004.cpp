#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node_t {
	int          level;
	vector<int > child;
}node_t;

const int maxn = 100;
int n, m, ptr = 0;
node_t tree[maxn];
bool inq[maxn];
int leaves[maxn];//记录每层叶子数

void bfs(node_t& t) {
	queue<node_t > q;//注意此处入队是 tree[] 元素的副本, 即退出 bfs() 后 tree[] 的值是没有被修改的————即在 bfs() 内我们修改了 t.level, 但退出 bfs() 你会发现相应的 tree[].level 仍是初始值 0; 但我们这里退出 bfs() 并不去使用 tree[] 元素所以总体上并没问题
	t.level = 0;//初始化

	q.push(t);
	inq[1] = true;
	while (!q.empty()) {
		node_t front = q.front();
		q.pop();

		int leaves_num = front.child.size();
		int level = front.level;
		ptr = level;//记录元素个数: 因为每趟循环都会覆盖, 所以到最后肯定是最深层即元素个数
		if (leaves_num == 0)    leaves[level]++;

		for (int i = 0; i < (int)front.child.size(); ++i) {
			int child = front.child[i];
			tree[child].level = level + 1;

			if (!inq[child]) {
				q.push(tree[child]);
				inq[child] = true;
			}
		}
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	if (n == 0)    return 0;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int node, num;
		cin >> node >> num;
		for (int j = 0; j < num; ++j) {
			int inp;
			cin >> inp;
			tree[node].child.push_back(inp);
		}
	}

	/* 2. MAIN LOGIC */
	bfs(tree[1]);

	/* 3. OUTPUT MODULE */
	cout << leaves[0];
	for (int i = 1; i <= ptr; ++i)    cout << " " << leaves[i];

	return 0;
}