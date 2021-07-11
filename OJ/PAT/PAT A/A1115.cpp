#include <iostream>
#include <queue>
using namespace std;

typedef struct node_t {
	int data, level;
	struct node_t* left, * right;
}node_t;

const int maxn = 1000;
int n, level[maxn], ptr = 0;

/* 插入结点 */
void insert(node_t *&t, int v) {
	if (t == NULL) {
		node_t* node = new node_t;
		node->data = v;
		node->left = node->right = NULL;
		t = node;
		return;
	}

	if (v <= t->data)    insert(t->left, v);
	else    insert(t->right, v);
}

/* 层序遍历: 带层数 */
void level_travesal(node_t* t) {
	queue<node_t*> q;
	t->level = 0;
	q.push(t);
	while (!q.empty()) {
		node_t* front = q.front();
		q.pop();

		int this_level = front->level;
		ptr = this_level;
		level[ptr]++;

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
	node_t* root = NULL;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int data;
		cin >> data;
		insert(root, data);
	}

	/* 2. MAIN LOGIC */
	level_travesal(root);

	/* 3. OUTPUT MODULE */
	int last1 = level[ptr], last2 = level[ptr - 1];
	cout << last1 << " + " << last2 << " = " << last1 + last2;

	return 0;
}