#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 31;
int n;
int post[maxn], in[maxn];
bool inq[maxn];
vector<int > level;

/* 根据后续-中序建树: 其中四个参数范围均是闭区间 */
node_t* post_in_create(int postL, int postR, int inL, int inR) {
	if (postL > postR)    return NULL;

	node_t* node = new node_t;
	int root;
	for (int i = inL; i <= inR; ++i) {
		if (in[i] == post[postR]) {
			root = i;
			break;
		}
	}
	int left_len = root - inL, right_len = inR - root;

	node->data = in[root];
	node->left = post_in_create(postL, postL + left_len - 1, inL, root - 1);
	node->right = post_in_create(postR - right_len, postR - 1, root + 1, inR);
	return node;
}

// ======== 注: 入队判断去掉才是 AC 代码(至于为什么我还不清楚, 所以暂时记着) ==========
/* 层序遍历: 常规 bfs() 广度搜索 */
void level_transvel(node_t* t) {
	queue<node_t * > q;
	q.push(t);
	inq[t->data] = true;//////////////////////////////暂时想不懂为什么 bfs() 的入队判断, 在层序遍历加上判断会 PA
	while (!q.empty()) {
		node_t *front = q.front();
		q.pop();
		level.push_back(front->data);

		if (front->left && !inq[front->left->data]) {//////////////////////////////暂时想不懂为什么 bfs() 的入队判断, 在层序遍历加上判断会 PA
			q.push(front->left);
			inq[front->left->data] = true;//////////////////////////////暂时想不懂为什么 bfs() 的入队判断, 在层序遍历加上判断会 PA
		}
		if (front->right && !inq[front->right->data]) {//////////////////////////////暂时想不懂为什么 bfs() 的入队判断, 在层序遍历加上判断会 PA
			q.push(front->right);
			inq[front->right->data] = true;//////////////////////////////暂时想不懂为什么 bfs() 的入队判断, 在层序遍历加上判断会 PA
		}
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> post[i];
	for (int i = 0; i < n; ++i)    cin >> in[i];

	/* 2. MAIN LOGIC */
	node_t* tree = post_in_create(0, n - 1, 0, n - 1);
	level_transvel(tree);

	/* 3. OUTPUT MODULE */
	cout << level[0];
	for (int i = 1; i < (int)level.size(); ++i)    cout << " " << level[i];

	return 0;
}