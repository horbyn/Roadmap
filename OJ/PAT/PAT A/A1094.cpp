#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node_t {
	int level;
	vector<int > child;
}node_t;

const int maxn = 100;
int n, m;
int gen[maxn], ptr = 0;//记录每一层(每一代)的人数、数组最多有几个元素
bool inq[maxn] = { false };
node_t tree[maxn];

void bfs(node_t& t) {
	queue<node_t > q;//注意此处入队是 tree[] 元素的副本, 即退出 bfs() 后 tree[] 的值是没有被修改的————即在 bfs() 内我们修改了 t.level, 但退出 bfs() 你会发现相应的 tree[].level 仍是初始值 0; 但我们这里退出 bfs() 并不去使用 tree[] 元素所以总体上并没问题
	t.level = 1;//初始化
	gen[t.level] = 1;

	q.push(t);
	inq[1] = true;

	while (!q.empty()) {
		node_t front = q.front();
		q.pop();

		int num = (int)front.child.size();//这一层孩子数
		int this_gen = front.level + 1;//这一层是第几代
		gen[this_gen] += num;
		ptr = this_gen;//每次进入循环都会覆盖前面的值, 当最后一次进入循环必是数组元素个数

		for (int i = 0; i < num; ++i) {
			int child = front.child[i];
			tree[child].level = this_gen;

			if (!inq[child]) {
				q.push(tree[child]);
				inq[child] = true;
			}
		}
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int idx, num;
		cin >> idx >> num;
		for (int j = 0; j < num; ++j) {
			int inp;
			cin >> inp;
			tree[idx].child.push_back(inp);
		}
	}

	/* 2. MAIN LOGIC */
	bfs(tree[1]);
	int max_gen = -1, max_level = -1;
	for (int i = 0; i < ptr; ++i) {
		if (gen[i] > max_gen) {
			max_gen = gen[i];
			max_level = i;
		}
	}

	/* 3. OUTPUT MODULE */
	cout << max_gen << " " << max_level;

	return 0;
}