#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct node_t {
	int data, level;
	struct node_t* left, * right;
}node_t;

const int maxn = 30;
int n, Ain[maxn], Apost[maxn];
int level_num[maxn], ptr = 0;
vector<int > level;

/* 双序建树: 根据中序后序建树 */
node_t* create(int postB, int postE, int inB, int inE) {
	if (postB > postE)    return NULL;

    //找根并划分子树: 根据后序确定根, 根据中序确定左右子树
	node_t* node = new node_t;
	node->data = Apost[postE];
	int root;
	for (root = inB; root <= inE; ++root)
		if (Ain[root] == Apost[postE])    break;
	int len_left = root - inB;

	node->left = create(postB, postB + len_left - 1, inB, root - 1);
	node->right = create(postB + len_left, postE - 1, root + 1, inE);
	return node;
}

/* 层序遍历 */
void level_travesal(node_t* t) {
	queue<node_t*> q;
	t->level = 0;
	q.push(t);
	while (!q.empty()) {
		node_t* front = q.front();
		q.pop();

        //保存每层结点数
		int this_level = front->level;
		ptr = this_level;//ptr 相当于指针, 因为遍历一层都会覆盖前一层的值, 所以最后必是最大层数
		level_num[this_level]++;
		level.push_back(front->data);

		if (front->left) {
			front->left->level = this_level + 1;
			q.push(front->left);
		}
		if (front->right) {
			front->right->level = this_level + 1;
			q.push(front->right);
		}
	}
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> Ain[i];
	for (int i = 0; i < n; ++i)    cin >> Apost[i];

	/* 2. MAIN LOGIC */
	node_t* root = create(0, n - 1, 0, n - 1);
	level_travesal(root);

	/* 3. OUTPUT MODULE */
	cout << level[0];
	int p = 1, flag = 1, l = 1;
	while (p < (int)level.size()) {
		int num = level_num[l];
        //用 -1 来控制交替输出
		if (flag == 1) {
			for (int i = 0; i < num; ++i) {
				cout << " " << level[p++];
			}
		}
		else if (flag == -1) {
			p = p + num - 1;
			for (int i = 0; i < num; ++i) {
				cout << " " << level[p--];
			}
			p = p + num + 1;
		}
		flag *= -1;
		l++;
	}

	return 0;
}