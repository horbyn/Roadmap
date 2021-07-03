#include <iostream>
#include <queue>
using namespace std;

typedef struct orientation_t {
	int x, y, z;
}ori_t;

const int maxx = 1286, maxy = 128, maxz = 60;
int m, n, l, t, num = 0;
int martix[maxx][maxy][maxz];
bool vis[maxz][maxx][maxy] = { false };

int arr_x[] = { 1,0,-1,0,0,0 };
int arr_y[] = { 0,-1,0,1,0,0 };
int arr_z[] = { 0,0,0,0,1,-1 };

void bfs(int x, int y, int z) {
	queue<ori_t > q;
	ori_t tmp;
	tmp.x = x; tmp.y = y; tmp.z = z;
	q.push(tmp);
	vis[z][x][y] = true;
	while (!q.empty()) {
		ori_t front = q.front();
		num++;
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int new_x = front.x + arr_x[i];
			int new_y = front.y + arr_y[i];
			int new_z = front.z + arr_z[i];
			if ((new_x < 0 || new_x >= m) || (new_y < 0 || new_y >= n) || (new_z < 0 || new_z >= l))    continue;

			if (martix[new_z][new_x][new_y] == 1 && !vis[new_z][new_x][new_y]) {
				tmp.x = new_x; tmp.y = new_y; tmp.z = new_z;
				q.push(tmp);
				vis[new_z][new_x][new_y] = true;
			}
		}
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> m >> n >> l >> t;
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < n; ++k) {
				cin >> martix[i][j][k];
			}
		}
	}

	/* 2. MAIN LOGIC */
	int sum = 0;
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < n; ++k) {
				if (martix[i][j][k] == 1 && !vis[i][j][k])    bfs(j, k, i);
				if (num >= t)    sum += num;
				num = 0;
			}
		}
	}

	/* 3. OUTPUT MODULE */
	cout << sum;
	return 0;
}