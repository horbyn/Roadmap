#include <iostream>
#include <queue>
using namespace std;

static const int max_x = 1286;
static const int max_y = 128;
static const int max_z = 60;
struct node_t {
	int x, y, z;
};
static struct node_t node;//临时变量，存放当前访问的坐标点
static bool inq[max_z][max_x][max_y] = { false };//记录坐标点状态是否已入队
static int martix[max_z][max_x][max_y];//存放输入矩阵
static int m, n, l, t;
static int coor_x[] = { 0, 0, 1, -1, 0, 0 };//增量数组
static int coor_y[] = { 1, -1, 0, 0, 0, 0 };
static int coor_z[] = { 0, 0, 0, 0, 1, -1 };

static bool is_valid(int x, int y, int z) {
	if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)
		return false;
	if (martix[z][x][y] == 0 || inq[z][x][y] == true)
		return false;
	return true;
}

static int bfs(struct node_t s) {
	int count = 1;
	queue<struct node_t> q;
	q.push(s);
	inq[s.z][s.x][s.y] = true;//入队时设置已入队
	while (!q.empty()) {
		struct node_t top = q.front();//取出队头
		q.pop();
		for (int i = 0; i < 6; ++i) {//访问队头元素——访问其附近所有点
			node.x = top.x + coor_x[i];
			node.y = top.y + coor_y[i];
			node.z = top.z + coor_z[i];
			if (is_valid(node.x, node.y, node.z)) {
				q.push(node);
				inq[node.z][node.x][node.y] = true;
				count++;
			}
		}
	}
	if (count >= t)    return count;
	else    return 0;
}

int main() {
	/* 1. 输入 */
	cin >> m >> n >> l >> t;
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < n; ++k)
				cin >> martix[i][j][k];

	/* 2. 主逻辑 */
	int volumn_amount = 0;
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < n; ++k) {
				if (martix[i][j][k] == 1 && inq[i][j][k] == false) {
					node_t cur;
					cur.z = i; cur.x = j; cur.y = k;
					int n = bfs(cur);
					volumn_amount += n;
				}
			}
		}
	}

	/* 3. 输出 */
	cout << volumn_amount;

	return 0;
}