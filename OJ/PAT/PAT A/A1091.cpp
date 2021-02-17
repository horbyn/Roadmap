#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

static const int max_x = 1286;
static const int max_y = 128;
static const int max_z = 60;
struct node_t {
	int x;
	int y;
};
static struct node_t node;//临时变量存放当前访问的坐标点
static bool inq[max_x][max_y];//记录坐标点状态是否已入队
static int martix[max_z][max_x][max_y];//存放输入矩阵
static int tmp[max_x][max_y];
static int m, n;
static int coor_x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };//增量数组
static int coor_y[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

static bool is_valid(int x, int y) {
	if (x < 0 || x >= m || y < 0 || y >= n)    return false;
	if (tmp[x][y] == 0 || inq[x][y] == true)    return false;
	return true;
}

static int bfs(struct node_t &s) {
	int count = 1;
	queue<struct node_t> q;
	q.push(s);
	inq[s.x][s.y] = true;//入队时设置已入队
	while (!q.empty()) {
		struct node_t top = q.front();//取出队头
		s = top;//记录每次出队的坐标，方便找到最后一个出队的点
		q.pop();
		for (int i = 0; i < 8; ++i) {//访问队头元素——访问其附近所有点
			node.x = top.x + coor_x[i];
			node.y = top.y + coor_y[i];
			if (is_valid(node.x, node.y)) {
				q.push(node);
				inq[node.x][node.y] = true;
				count++;
			}
		}
	}
	return count;
}

/* 找起点 */
static struct node_t find_next_point
(struct node_t p, int (&martix)[max_x][max_y]) {
	static struct node_t ret;
	ret.x = -1; ret.y = -1;
	for (int i = p.x; i < m; ++i) {
		for (int j = p.y; j < n; ++j) {
			if (martix[i][j] == 1 && inq[i][j] == false) {
				ret.x = i;
				ret.y = j;
				return ret;
			}
		}
		p.y = 0;
	}
	return ret;
}

static void get_martix(int (&ret)[max_x][max_y], int i) {
	for (int j = 0; j < m; ++j) {
		for (int k = 0; k < n; ++k) {
			ret[j][k] = martix[i][j][k];
		}
	}
}

int main() {
	int l, t;

	/* 1. 输入 */
	cin >> m >> n >> l >> t;
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < n; ++k)
				cin >> martix[i][j][k];

	/* 2. 主逻辑 */
	int volumn_amount = 0;
	struct node_t cur_point;
	for (int i = 0; i < l; ++i) {
		get_martix(tmp, i);//获取第 i 个二维矩阵
		//初始化
		cur_point.x = 0; cur_point.y = 0;//初始化起点
		memset(inq, (int)false, m * max_x);//初始化状态数组

		while (cur_point.x < m && cur_point.y < n) {
			//找下一个为 "1" 的点
			struct node_t next_point = find_next_point(cur_point, tmp);
			if (next_point.x != -1 && next_point.y != -1) {
				int n = bfs(next_point);//执行完 bfs()，next_point 会更新为最后一个出队的坐标，减少查找下一个 "1" 的时间
				cur_point = next_point;
				if (n >= t)    volumn_amount += n;
			}
			//更新下一个点
			if (cur_point.y < n - 1)    cur_point.y++;
			else if (cur_point.y == n - 1) {
				cur_point.x++;
				cur_point.y = 0;
			}
		}
	}

	/* 3. 输出 */
	cout << volumn_amount;

	return 0;
}